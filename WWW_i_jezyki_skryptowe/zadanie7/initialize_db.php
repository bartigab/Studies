<?php
try {
    $pdo = new PDO('sqlite:' . __DIR__ . '/database/notatki.db');
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $pdo->exec("CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY,
        username TEXT UNIQUE NOT NULL,
        firstname TEXT NOT NULL,
        lastname TEXT NOT NULL,
        password TEXT NOT NULL
    )");

    $pdo->exec("CREATE TABLE IF NOT EXISTS notes (
        id INTEGER PRIMARY KEY,
        user_id INTEGER NOT NULL,
        content TEXT NOT NULL,
        created_at TEXT NOT NULL,
        FOREIGN KEY(user_id) REFERENCES users(id)
    )");

    $pdo->exec("CREATE TABLE IF NOT EXISTS guests (
        id TEXT PRIMARY KEY,
        ip_address TEXT NOT NULL,
        registration_time TEXT NOT NULL
    )");

    $pdo->exec("CREATE TABLE IF NOT EXISTS visits (
        id INTEGER PRIMARY KEY,
        guest_id TEXT,
        ip_address TEXT NOT NULL,
        uri TEXT NOT NULL,
        visit_time TEXT NOT NULL,
        user_id INTEGER,
        event TEXT,
        FOREIGN KEY(guest_id) REFERENCES guests(id),
        FOREIGN KEY(user_id) REFERENCES users(id)
    )");

    $pdo->exec("INSERT INTO users (username, firstname, lastname, password) VALUES ('admin', 'Admin', 'Admin', 'admin')");
    
    echo "Database initialized successfully.";
} catch (PDOException $e) {
    echo "Database initialization failed: " . $e->getMessage();
}
?>
