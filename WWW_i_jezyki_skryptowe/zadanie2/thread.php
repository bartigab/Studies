<?php
$path = explode('/',dirname(__FILE__));
$dirname = array_pop($path);
$username = array_pop($path);
$path = implode('/',$path);
$tasks = array();
foreach(scandir( "$path/$username" ) as $dir) if( is_dir("$path/$username/$dir") and $dir!='.' and $dir!='..') $tasks[] = $dir; 


include('data.php');

$path = explode('/',dirname(__FILE__));
$dirname = array_pop($path);
$username = array_pop($path);
$path = implode('/',$path);
$tasks = array();

foreach (scandir( "$path/$username" ) as $dir)
    if (is_dir("$path/$username/$dir") and $dir!='.' and $dir!='..')
        $tasks[] = $dir;

$data = get_data();

if (isset($_GET['id']))
    $thread = get_thread($data, $_GET['id']);
else
    $thread = null;

if ($_SERVER['REQUEST_METHOD'] == 'POST' and $thread) {
    if (isset($_POST['post_id'])) {
        if (isset($_POST['post_content']) and isset($_POST['post_author'])) {
            edit_post($data, $_GET['id'], $_POST['post_id'], $_POST['post_author'], $_POST['post_content']);
            header("Location: ./thread.php?id=".$_GET['id']);
        }
    } else {
        if (isset($_POST['post_content']) and isset($_POST['post_author'])) {
            add_post($data, $_GET['id'], $_POST['post_author'], $_POST['post_content']);
            header("Location: ./thread.php?id=".$_GET['id']);
        }
    }
}

if (isset($_GET['action']) and isset($_GET['post'])) {
    if ($_GET['action'] == 'delete') {
        delete_post($data, $_GET['id'], $_GET['post']);
        header("Location: ./thread.php?id=".$_GET['id']);
    }
}
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

<div id="container">




<main>
        <nav class="NAV">
            <?php if ($thread) : ?>
                <?php $ids = get_thread_nearests_ids($data, $_GET['id']); ?>
        
                    <?php if ($ids[0] != null) : ?>
                        <a href="<?="./thread.php?id=".$ids[0]?>" title="Previous thread" target="_self">Poprzedni temat</a>
                    <?php endif; ?>
             
                    <a href="./" title="Powrót do głównej strony" target="_self">Powrót do głównej strony</a>
             
              
                    <?php if ($ids[1] != null) : ?>
                        <a href="<?="./thread.php?id=".$ids[1]?>" title="Next thread" target="_self">Nastepny</a>
                    <?php endif; ?>
            
            <?php endif; ?>
            
        </nav>
        <section>
            <?php if ($thread) : ?>
                <div class="thread">
                        <h2><?=$thread['title']?></h2>
                        <p><?=$thread['description']?></p>
                        <footer>
                            <p>ID: <?=$thread['id']?></p>
                            <p>Author: <?=$thread['author']?></p>
                            <p>Date: <?=$thread['date']?></p>
                        </footer>
                </div>

                <?php foreach ($thread['posts'] as $post) : ?>
                    <div class="post">
                        <p><?=$post['content']?></p>
                        <footer>
                            <div class="controls">
                            <a href="<?="./thread.php?id=".$thread['id']."&post=".$post['id']."&action=edit#content"?>" title="Edit post" target="_self">Edycja komentarza</a>
                                <a href="<?="./thread.php?id=".$thread['id']."&post=".$post['id']."&action=delete"?>" title="Delete post" target="_self">USUŃ KOMENTARZ</a>
                            </div>
                            <p>ID: <?=$post['id']?></p>
                    <?php if (isset($post['author'])) : ?>
                        <p>Author: <?=$post['author']?></p>
                    <?php endif; ?>
                    <p>Date: <?=$post['date']?></p>
                        </footer>
                    </div>
                <?php endforeach; ?>
            <?php endif; ?>
                    </section>
    </main>


    <aside>
    
    <form action="./thread.php?id=<?=$_GET['id']?>" method="POST">
        <?php if (isset($_GET['action']) and isset($_GET['post'])) : ?>
            <?php if ($_GET['action'] == 'edit') : ?>
                <?php $post = get_post($thread, $_GET['post']); ?>
                <center><h3>Edytuj</h3></center>
                <?php $content = str_replace("<br />", "\r\n", $post['content']); ?><br><br></center>
                <center><textarea id="content" name="post_content" rows="10" cols="70" required><?=$content?></textarea><br><br></center>
                <center><input type="text" name="post_author" value="<?=$post['author']?>" required><br><br></center>
                <center><input type="hidden" name="post_id" value="<?=$post['id']?>"></center>
                <center> <input type="submit" value="Edit post"></center>
            <?php endif; ?>
        <?php else : ?>
            <center><h3>Dodaj nowy komentarz</h3></center>
            <center><textarea name="post_content"  rows="10" cols="70" placeholder="Post content" required></textarea><br><br></center>
            <center><input type="text" name="post_author" placeholder="Author" required><br><br></center>
            <center> <input type="submit" value="Add post"></center>
        <?php endif; ?>

    </form>
        </aside>

    <footer id="dol">
    Stopka wiadomości: TWWW - User: <?=$username?>
<p>Stopka dokumentu: TWWW - IR - WIiT PP - <?=date("Y")?></p>
</footer>


</div>
</body>
</html>