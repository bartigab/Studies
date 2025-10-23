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


<div id="container">



<header id="blog"><h1>Mój blog</h1></header>

<section>
<?php

$date_format = "Y-m-d H:i:s";
$token = "<footer><p>Data: ";
$lines = file("dane.php");
if ($lines and !empty($lines[0]) )
{
    $tmp = explode('"',$lines[0]);
    if (isset($tmp[1]) && $tmp[1]>0)
    {
        $nr=$tmp[1];
    }
    else
    {
        $nr=1;
    }
    foreach( $lines as $line){
        if (strstr($line, $token))
        {
        $last_date = substr ($line, strlen($token), strlen( date($date_format)));
        break;

        }
    }
} 


if( isset($_POST['title']) and $_POST['title']!="")
{
    $post = '<article nr="'.(( empty($nr) )?1:($nr+1))."\" >\n";
    $post .= "<header><h2>".htmlentities($_POST['title'])."</h2></header>\n";
    $post .= "<div>\n".str_replace("\r\n","<Br>", htmlentities($_POST['body']))."\n</div>\n";
    $post .= "<footer><p>Data: ".date("Y-m-d H:i:s")."; IP ".$_SERVER['HTTP_X_FORWARDED_FOR']."</p></footer>\n";
    $post .= "<br></article>\n";

    file_put_contents("dane.php", $post.file_get_contents("dane.php") );
    header("Location: index.php");
    exit;
}


?>    
<?php include("dane.php"); ?>
</section>





<aside>
<form action="" method="post" accept-charset="utf-8"
enctype="application/x-www-form-urlencoded">
    <header> <center><h3> Wpisz komunikat</h2></center> </header>
    <center><input name="title" id="title" type="text" placeholder="TYTUŁ"></center>
    <br>
    <textarea name="body" id="body" cols="80" rows="10" placeholder="TREŚĆ"></textarea>
    <br>
    <center><button type="submit">Zatwierdź</button></center>

</form>
    <footer>
            <p>Ostatni wpis: <?php echo(empty($last_date))?'brak wpisow':$last_date?></p>
            <p>Liczba wpisow: <?php echo(empty($nr))?0:$nr?></p>
</footer>
</aside>






<footer id="dol">
    Stopka wiadomości: TWWW - User: <?=$username?>
<p>Stopka dokumentu: TWWW - IR - WIiT PP - <?=date("Y")?></p>
</footer>


</div>
</body>
</html>