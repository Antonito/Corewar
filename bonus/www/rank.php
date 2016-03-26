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
        echo "<p style=\"background-color:rgba(0, 255, 0, 0.5);\">The Ranking !!</p>";
	$dbhost = 'localhost:3306';
   	$dbuser = 'root';
   	$dbpass = 'tekdoom';
	$dbname = 'tekdoom';
   	$conn = mysqli_connect($dbhost, $dbuser, $dbpass, $dbname);
   	if(! $conn )
   	{
     		die('Could not connect: ' . mysql_error());
   	}
	
	$sql = "SELECT classement, login, score FROM player GROUP BY classement ASC";
	$result = mysqli_query($conn, $sql);

	if (mysqli_num_rows($result) > 0) {
    	// output data of each row
	echo "<p style=\"background-color:rgba(0, 255, 0, 0.5);\">";
    	while($row = mysqli_fetch_assoc($result)) {
        	echo $row["classement"]. " - " . $row["login"]. " - Score: " . $row["score"]. "<br>";
    	}
	} else {
    	echo "0 results";
	}
	echo "</p>";
   	mysqli_close($conn);
      ?>
    </p>
  </body>
</html>
