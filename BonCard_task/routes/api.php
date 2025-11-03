<?php

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Route;
use App\Http\Controllers\API\CardController;
use App\Http\Controllers\API\AuthTokenController;

// Public token-based auth endpoints (no sessions, no CSRF)
Route::post('/register', [AuthTokenController::class, 'register']);
Route::post('/login', [AuthTokenController::class, 'login']);

// Use simple token auth middleware (auth.token) which reads tokens from access_tokens table
Route::middleware(['auth.token'])->group(function () {
    Route::get('/user', function (Request $request) {
        return $request->user();
    });

    // Token-auth friendly "me" endpoint
    Route::get('/me', [AuthTokenController::class, 'me']);
    Route::post('/logout', [AuthTokenController::class, 'logout']);

    // API resource routes for cards (protected by our token middleware)
    Route::apiResource('cards', CardController::class);
});
