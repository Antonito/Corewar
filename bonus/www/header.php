
<html>
  <head>
    <title>My First Array</title>
  </head>
  <body>
    <p>
      <?php
	session_start();
	if (isset($_SESSION["login"]))
	{
		echo "Welcome ".$_SESSION["login"]."<br>";
		echo "<a href='ok.php' style='border:2px solid red;color: hotpink;'>Upload a Champ</a>        ";
		echo "<a href='all.php' style='border:2px solid red;color: hotpink;'>launch a fight</a>  ";
		echo "<a href='rank.php' style='border:2px solid red;color: hotpink;'>see the Ranking</a>  ";
		echo "<a href='index.php' style='border:2px solid red;color: hotpink;'>Logout</a><br><br>";
	}
	else {
		echo '<script>window.location.replace("index.php");</script>';
	}	
      ?>
    </p>
  </body>
</html>
