<?php

namespace App\Http\Controllers\API;

use App\Http\Controllers\Controller;
use App\Models\User;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Hash;
use Illuminate\Support\Facades\DB;
use Illuminate\Validation\Rules;

class AuthTokenController extends Controller
{
    public function register(Request $request)
    {
        $validated = $request->validate([
            'name' => ['required', 'string', 'max:255'],
            'email' => ['required', 'string', 'email', 'max:255', 'unique:users,email'],
            'password' => ['required', 'confirmed', Rules\Password::defaults()],
        ]);

        $user = User::create([
            'name' => $validated['name'],
            'email' => $validated['email'],
            'password' => Hash::make($validated['password']),
            'created_at' => now(),
        ]);

   
    $user->last_login = now();
    $user->save();

    
    $token = bin2hex(random_bytes(32));
    DB::table('access_tokens')->insert([
        'id_user' => $user->id,
        'token' => $token,
        'created' => now(),
    ]);

    return response()->json([
        'token' => $token,
        'user' => $user,
    ], 201);
    }

    public function login(Request $request)
    {
        $credentials = $request->validate([
            'email' => ['required', 'email'],
            'password' => ['required', 'string'],
        ]);

        $user = User::where('email', $credentials['email'])->first();
        if (!$user || !Hash::check($credentials['password'], $user->password)) {
            return response()->json(['message' => 'Invalid credentials'], 422);
        }

      
        DB::table('access_tokens')->where('id_user', $user->id)->delete();

       
        $user->last_login = now();
        $user->save();

        $token = bin2hex(random_bytes(32));
        DB::table('access_tokens')->insert([
            'id_user' => $user->id,
            'token' => $token,
            'created' => now(),
        ]);

        return response()->json([
            'token' => $token,
            'user' => $user,
        ]);
    }

 
    public function logout(Request $request)
    {
    
        $header = $request->header('Authorization') ?: $request->bearerToken();
        $token = preg_replace('/^Bearer\s+/i', '', $header ?: '');
        if ($token) {
            DB::table('access_tokens')->where('token', $token)->delete();
        }
        return response()->noContent();
    }

    public function me(Request $request)
    {
        return response()->json($request->user());
    }
}
