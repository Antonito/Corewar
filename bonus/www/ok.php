<html>
  <head>
    <title>Corewar</title>
  </head>
  <body>
    <p>
      <?php
	session_start();
	if (isset($_SESSION["login"]))
	{
		include "header.php";
	}
	else {
		echo '<script>window.location.replace("index.php");</script>';
	}	
	
	$dbhost = 'localhost:3306';
   	$dbuser = 'root';
   	$dbpass = 'tekdoom';
	$dbname = 'tekdoom';
   	$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
   	if(! $conn )
   	{
     		die('Could not connect: ' . mysql_error());
   	}
	
	$sql = "SELECT login FROM player WHERE login LIKE \"".$_SESSION['login']."\"";
	$result = mysqli_query($conn, $sql);

	if (mysqli_num_rows($result) <= 0) {
		$newsql = "INSERT INTO player VALUES (NULL, '".$_SESSION['login']."', 0, 0, 0)";
		$result = mysqli_query($conn, $newsql);
	}	
   	mysqli_close($conn);
      ?>
    </p>
  </body>
</html>
