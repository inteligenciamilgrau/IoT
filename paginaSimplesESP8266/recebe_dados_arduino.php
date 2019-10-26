<html>
 <head>
  <title>PHP Mil Grau</title>
 </head>
 <body>

<?php
   //https://www.hackster.io/detox/send-esp8266-data-to-your-webpage-no-at-commands-7ebfec

   if( $_REQUEST["LeituraAnalogica"]) 
   {
   echo " A leitura analógica é: ". $_REQUEST['LeituraAnalogica']. "%<br />";
   }
  
	
$var1 = $_REQUEST['LeituraAnalogica'];

$WriteMyRequest= "<?xml version = \"1.0\" ?><inputs><analog1>" . $var1 . "</analog1></inputs>";

file_put_contents('dados_arduino.xml', $WriteMyRequest);

?>

</body>
</html>
