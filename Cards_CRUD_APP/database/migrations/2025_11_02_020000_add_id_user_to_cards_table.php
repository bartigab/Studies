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
        if (! Schema::hasTable('cards')) {
            return;
        }

        if (! Schema::hasColumn('cards', 'id_user')) {
            Schema::table('cards', function (Blueprint $table) {
                // nullable for safety on existing rows; future creates will set owner
                $table->unsignedBigInteger('id_user')->nullable()->after('id')->index();
            });
        }
    }

    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        if (Schema::hasTable('cards') && Schema::hasColumn('cards', 'id_user')) {
            Schema::table('cards', function (Blueprint $table) {
                $table->dropIndex(['id_user']);
                $table->dropColumn('id_user');
            });
        }
    }
};
