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
	
	$sql = "SELECT login, score, victoire, defaite FROM player GROUP BY score DESC";
	$result = mysqli_query($conn, $sql);

	if (mysqli_num_rows($result) > 0) {
    	// output data of each row
	echo "<p style=\"background-color:rgba(0, 255, 0, 0.5);\">";
	$i = 1;
    	while($row = mysqli_fetch_assoc($result)) {
        	echo $i. " - " . $row["login"]. " - Score: " . $row["score"].  " - victoire: " . $row['victoire']. " - defaite: " .$row['defaite']."<br>";
		$i += 1;
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
