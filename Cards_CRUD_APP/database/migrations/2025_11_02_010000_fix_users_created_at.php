<?php

use Illuminate\Database\Migrations\Migration;
use Illuminate\Support\Facades\Schema;
use Illuminate\Support\Facades\DB;

return new class extends Migration
{
    /**
     * Run the migrations.
     */
    public function up(): void
    {
        // Update existing users that have NULL created_at to now()
        if (Schema::hasTable('users')) {
            DB::table('users')->whereNull('created_at')->update(['created_at' => now()]);
        }
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        // No-op: we won't revert timestamps to NULL
    }
};
