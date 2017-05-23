<?
session_start();
unset($_SESSION["email"]);
unset($_SESSION['id']);
session_destroy();
?>
<script> document.location = "http://localhost/assignment/index.php"; </script>
