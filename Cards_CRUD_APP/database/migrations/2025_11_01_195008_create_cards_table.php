<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;

return new class extends Migration
{
    /**
     * Run the migrations.
     */
    public function up(): void
    {
        if (!Schema::hasTable('cards')) {
            Schema::create('cards', function (Blueprint $table) {
                $table->id();
                $table->string('card_number', 20)->unique();
                $table->string('pin', 8);
                $table->dateTime('activation');
                $table->date('expires_on');
                $table->decimal('balance', 10, 2)->default(0.00);
                // use custom timestamp column names as requested: created, updated
                $table->timestamp('created')->nullable();
                $table->timestamp('updated')->nullable();
            });
        }
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::dropIfExists('cards');
    }
};
