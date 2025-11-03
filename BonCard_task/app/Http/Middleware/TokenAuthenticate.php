<?php

namespace App\Http\Middleware;

use Closure;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Auth;

class TokenAuthenticate
{
    /**
     * Handle an incoming request.
     */
    public function handle(Request $request, Closure $next)
    {
        $header = $request->header('Authorization') ?: $request->bearerToken();
        if (!$header) {
            return response()->json(['message' => 'Unauthenticated'], 401);
        }

        // Extract token (Bearer ...)
        $token = preg_replace('/^Bearer\s+/i', '', $header);
        if (!$token) {
            return response()->json(['message' => 'Unauthenticated'], 401);
        }

        $row = DB::table('access_tokens')->where('token', $token)->first();
        if (!$row) {
            return response()->json(['message' => 'Unauthenticated'], 401);
        }

        // Log in the user for the request (access_tokens.id_user)
        Auth::loginUsingId($row->id_user);

        return $next($request);
    }
}
