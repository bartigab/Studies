<?php
include 'includes/config.php';
include 'includes/functions.php';
include 'includes/header.php';

if (!isLoggedIn() || $_SESSION['username'] != 'admin') {
    header('Location: index.php');
    exit;
}

logUserActivity($pdo, $_SESSION['user_id'], 'view_activity');

$stmt = $pdo->query("SELECT * FROM visits ORDER BY visit_time DESC");
$activities = $stmt->fetchAll(PDO::FETCH_ASSOC);
?>

<h1>Aktywność</h1>

<table>
    <tr>
        <th>ID Gościa</th>
        <th>IP</th>
        <th>URI</th>
        <th>Data</th>
        <th>ID Użytkownika</th>
        <th>Zdarzenie</th>
    </tr>
    <?php foreach ($activities as $activity): ?>
        <tr>
            <td><?= $activity['guest_id'] ?></td>
            <td><?= $activity['ip_address'] ?></td>
            <td><?= $activity['uri'] ?></td>
            <td><?= $activity['visit_time'] ?></td>
            <td><?= $activity['user_id'] ?></td>
            <td><?= $activity['event'] ?></td>
        </tr>
    <?php endforeach; ?>
</table>

<?php include 'includes/footer.php'; ?>
