<?php

namespace App\Http\Controllers\API;


use App\Http\Controllers\Controller;
use App\Models\Card;
use App\Http\Requests\StoreCardRequest;
use App\Http\Requests\UpdateCardRequest;
use Illuminate\Support\Facades\Auth;

class CardController extends Controller
{
    /**
     * Display a listing of the resource.
     */
    public function index()
    {
        $userId = Auth::id();
        return Card::where('id_user', $userId)->orderByDesc('id')->paginate(10);
    }

    /**
     * Store a newly created resource in storage.
     */
    public function store(StoreCardRequest $request)
    {
        $data = $request->validated();
        $data['id_user'] = Auth::id();
        $card = Card::create($data);
        return response()->json($card, 201);
    }

    /**
     * Display the specified resource.
     */
    public function show(Card $card)
    {
        if ($card->id_user !== Auth::id()) {
            abort(403);
        }
        return $card;
    }

    /**
     * Update the specified resource in storage.
     */
    public function update(UpdateCardRequest $request, Card $card)
    {
        if ($card->id_user !== Auth::id()) {
            abort(403);
        }
        $card->update($request->validated());
        return $card;
    }

    /**
     * Remove the specified resource from storage.
     */
    public function destroy(Card $card)
    {
        if ($card->id_user !== Auth::id()) {
            abort(403);
        }
        $card->delete();
        return response()->noContent();
    }
}
