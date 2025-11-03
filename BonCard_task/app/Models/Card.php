<?php


namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;
use App\Models\User;

class Card extends Model
{
    use HasFactory;


    protected $fillable = [
        'card_number',
        'pin',
        'activation',
        'expires_on',
        'balance',
        'id_user',
    ];
    protected $casts = [
        'activation' => 'datetime',
        'expires_on' => 'date',
        'balance' => 'decimal:2',
    ];

    public const CREATED_AT = 'created';
    public const UPDATED_AT = 'updated';

    public function user()
    {
        return $this->belongsTo(User::class, 'id_user');
    }
}