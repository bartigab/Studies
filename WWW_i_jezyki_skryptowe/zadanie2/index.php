<?php
$path = explode('/',dirname(__FILE__));
$dirname = array_pop($path);
$username = array_pop($path);
$path = implode('/',$path);
$tasks = array();
foreach(scandir( "$path/$username" ) as $dir) if( is_dir("$path/$username/$dir") and $dir!='.' and $dir!='..') $tasks[] = $dir; 

?>
<!DOCTYPE html>
<html>
<head>  
    <link rel="stylesheet" href="style.css">
  <title>TWWW - User: <?=$username?>, <?=$dirname?></title>
  <meta charset="UTF-8">
  <meta http-equiv="Cache-Control" content="no-store, no-cache, must-revalidate" >
  <meta http-equiv="Pragma" content="no-cache" >

</head>
<body>
<header>
<h1><?=$dirname?></h1>
</header>
<nav>
<a href="<?="/$username"?>" title="Strona początkowa serwisu" target="_self" >Strona początkowa serwisu</a> 
<?php foreach($tasks as $task){ ?>
<a href="<?="/$username/$task"?>/" title="<?=$task?>" target="_self" ><?=$task?></a> 
<?php } 
?>
</nav>


<?php
    include('data.php');

    foreach (scandir( "$path/$username" ) as $dir)
        if (is_dir("$path/$username/$dir") and $dir!='.' and $dir!='..')
            $tasks[] = $dir;

    $data = get_data();

    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        if (isset($_POST['thread_id'])) {
            if (isset($_POST['thread_title']) and isset($_POST['thread_content']) and isset($_POST['thread_author'])) {
                edit_thread($data, $_POST['thread_id'], $_POST['thread_title'], $_POST['thread_author'], $_POST['thread_content']);
                header("Location: ./");
            }
        } else {
            if (isset($_POST['thread_title']) and isset($_POST['thread_content']) and isset($_POST['thread_author'])) {
                add_thread($data, $_POST['thread_title'], $_POST['thread_author'], $_POST['thread_content']);
                header("Location: ./");
            }
        }
    }

    if (isset($_GET['action']) and isset($_GET['id'])) {
        if ($_GET['action'] == 'delete') {
            delete_thread($data, $_GET['id']);
            header("Location: ./");
        }
    }
?>

<div id="container">



<header id="blog"><h1>Mój blog</h1></header>


<section>
            <?php if ($data) : ?>
                <?php foreach ($data['threads'] as $thread) : ?>
                    <div class="thread">
                        <a href="<?="./thread.php?id=".$thread['id']?>" title="<?=$thread['title']?>">
                            <h3><?=$thread['title']?></h3>
                        </a>
                        <footer>
                            <div class="controls">
                                <a href="<?="./index.php?id=".$thread['id']."&action=edit#description"?>" title="Edytuj post" target='_self'>Edytuj post</a>
                                <a href="<?="./index.php?id=".$thread['id']."&action=delete"?>" title="Delete thread" target='_self'>Usuń post</a>
                            </div>
                            <p>
                            ID: <?=$thread['id']?>
                            Imię: <?=$thread['author']?>
                            Data: <?=$thread['date']?>
                            Ilosc wpisow: <?=count($thread['posts'])?>
                        </p>
                        </footer>
                    </div>
                <?php endforeach; ?>
            <?php else : ?>
                <h2>No threads</h2>
            <?php endif; ?>
        </section>






<aside>
<form action="./" method="POST">
        <?php if (isset($_GET['action']) and isset($_GET['id'])) : ?>
            <?php if ($_GET['action'] == 'edit') : ?>
                <?php $thread = get_thread($data, $_GET['id']); ?>
                <center><h3>Edytuj post</h3></center>
                <center><input type="text" name="thread_title" value="<?=$thread['title']?>" required></center>
                <?php $description = str_replace("<br />", "\r\n", $thread['description']); ?><br><br></center>
                <center><textarea id="description" name="thread_content" rows="10" cols="70" required><?=$description?></textarea><br><br></center>
                <center><input type="text" name="thread_author" value="<?=$thread['author']?>" required><br><br></center>
                <center><input type="hidden" name="thread_id" value="<?=$thread['id']?>"></center>
                <center><input type="submit" value="Edit thread"></center>
            <?php endif; ?>
        <?php else : ?>
            <center><h3>Dodaj post</h3></center>
            <center><input type="text" name="thread_title" placeholder="Tytuł" required><br><br> </center>
            <center><textarea id="content" name="thread_content" rows="10" cols="70" placeholder="Treść" required></textarea><br><Br> </center>
            <center><input type="text" name="thread_author" placeholder="Author" required><br><Br> </center>
            <center><input type="submit" value="Dodaj post"></center>
        <?php endif; ?>
    </form>



    <footer>
            <p>Ostatni wpis: <?php echo(empty($last_date))?'brak wpisow':$last_date?></p>
</footer>
</aside>






<footer id="dol">
    Stopka wiadomości: TWWW - User: <?=$username?>
<p>Stopka dokumentu: TWWW - IR - WIiT PP - <?=date("Y")?></p>
</footer>


</div>
</body>
</html>