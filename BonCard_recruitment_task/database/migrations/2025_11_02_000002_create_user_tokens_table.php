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
        // create a minimal access_tokens table (id, id_user, token, created)
        if (!Schema::hasTable('access_tokens')) {
            Schema::create('access_tokens', function (Blueprint $table) {
                $table->id();
                $table->unsignedBigInteger('id_user');
                $table->string('token', 128)->unique();
                $table->timestamp('created')->useCurrent();
            });
        }

        // remove old personal_access_tokens if present to avoid confusion
        if (Schema::hasTable('personal_access_tokens')) {
            Schema::dropIfExists('personal_access_tokens');
        }
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::dropIfExists('access_tokens');
    }
};
