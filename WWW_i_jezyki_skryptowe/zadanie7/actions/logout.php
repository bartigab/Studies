<?php
include '../includes/config.php';
include '../includes/functions.php';

if (isLoggedIn()) {
    logUserActivity($pdo, $_SESSION['user_id'], 'logout');
    session_destroy();
}
header('Location: ../index.php');
?>
