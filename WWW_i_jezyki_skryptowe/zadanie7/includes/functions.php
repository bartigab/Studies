<?php

function isLoggedIn() {
    return isset($_SESSION['user_id']);
}

function getUserNotes($pdo, $userId) {
    $stmt = $pdo->prepare("SELECT * FROM notes WHERE user_id = ? ORDER BY created_at DESC");
    $stmt->execute([$userId]);
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function getAllNotes($pdo) {
    $stmt = $pdo->query("SELECT notes.id, notes.content, notes.created_at, users.firstname, users.lastname 
                         FROM notes 
                         JOIN users ON notes.user_id = users.id 
                         ORDER BY notes.created_at DESC");
    return $stmt->fetchAll(PDO::FETCH_ASSOC);
}

function registerGuestVisit($pdo) {
    if (!isset($_COOKIE['guest_id'])) {
        $guestId = uniqid();
        setcookie('guest_id', $guestId, time() + (10 * 365 * 24 * 60 * 60)); // 10 years
        $stmt = $pdo->prepare("INSERT INTO guests (id, ip_address, registration_time) VALUES (?, ?, ?)");
        $stmt->execute([$guestId, $_SERVER['REMOTE_ADDR'], date('Y-m-d H:i:s')]);
    } else {
        $guestId = $_COOKIE['guest_id'];
    }

    $stmt = $pdo->prepare("INSERT INTO visits (guest_id, ip_address, uri, visit_time) VALUES (?, ?, ?, ?)");
    $stmt->execute([$guestId, $_SERVER['REMOTE_ADDR'], $_SERVER['REQUEST_URI'], date('Y-m-d H:i:s')]);
}

function logUserActivity($pdo, $userId, $event) {
    $stmt = $pdo->prepare("INSERT INTO visits (user_id, ip_address, uri, visit_time, event) VALUES (?, ?, ?, ?, ?)");
    $stmt->execute([$userId, $_SERVER['REMOTE_ADDR'], $_SERVER['REQUEST_URI'], date('Y-m-d H:i:s'), $event]);
}

?>
