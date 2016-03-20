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
		include "header.php";
	}
	else {
		echo '<script>window.location.replace("index.php");</script>';
	}	
	echo "Here you can upload your champ <br>";
      ?>
<form action="upload.php" method="post" enctype="multipart/form-data">
    <input type="file" id="file" name="file" />
  <input type="submit" value="Upload!" />
    </p>
  </body>
</html>
