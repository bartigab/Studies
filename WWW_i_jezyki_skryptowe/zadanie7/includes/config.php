<?php
session_start();

try {
    $pdo = new PDO('sqlite:' . __DIR__ . '/../database/notatki.db');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    echo "Database connection failed: " . $e->getMessage();
    exit;
}
?>
