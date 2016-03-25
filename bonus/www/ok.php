<html>
  <head>
    <title>Corewar</title>
  </head>
  <body>
    <p style="background-color:rgba(0, 255, 0, 0.5);">
      <?php
	session_start();
	if (isset($_SESSION["login"]))
	{
		include "header.php";
	}
	else {
		echo '<script>window.location.replace("index.php");</script>';
	}	
        echo "<p style=\"background-color:rgba(0, 255, 0, 0.5);\"> Here you can upload your champion </p>"
      ?>
<form action="upload.php" method="post" enctype="multipart/form-data">
    <input type="file" id="file" name="file" />
  <input type="submit" value="Upload!" />
    </p>
  </body>
</html>
