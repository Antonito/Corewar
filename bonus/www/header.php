
<html>
  <head>
    <title>My First Array</title>
    <link rel="stylesheet" type="text/css" href="style.css">
  </head>
  <body>
<video autoplay loop poster="polina.jpg" id="bgvid">
    <source src="polina.webm" type="video/webm">
    <source src="nico.mp4" type="video/mp4">
</video>
    <p>
      <?php
	session_start();
	if (isset($_SESSION["login"]))
	{
                echo "<p style=\"background-color:rgba(0, 255, 0, 0.5);\">Welcome ".$_SESSION['login']." <br> </p>";
		echo "<a href='ok.php' style='border:2px solid red;color: hotpink;'>Upload a Champ</a>        ";
		echo "<a href='all.php' style='border:2px solid red;color: hotpink;'>launch a fight</a>  ";
		echo "<a href='index.php' style='border:2px solid red;color: hotpink;'>Logout</a><br><br>";
	}
	else {
		echo '<script>window.location.replace("index.php");</script>';
	}	
      ?>
    </p>
  </body>
</html>
