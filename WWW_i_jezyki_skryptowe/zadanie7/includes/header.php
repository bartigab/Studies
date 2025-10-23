<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Notatki</title>
    <link rel="stylesheet" href="css/style.css">
</head>
<body>
    <header>
        <nav>
            <ul>
                <?php if (isLoggedIn()): ?>
                    <li><a href="notes.php">Moje Notatki</a></li>
                    <li><a href="activity.php">Aktywność</a></li>
                    <li><a href="/actions/logout.php">Wyloguj</a></li>
                <?php else: ?>
                    <li><a href="index.php">Strona główna</a></li>
                    <li><a href="register.php">Rejestracja</a></li>
                    <li><a href="login.php">Logowanie</a></li>
                <?php endif; ?>
            </ul>
        </nav>
    </header>
    <main>
