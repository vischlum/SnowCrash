#!/usr/bin/php
<?php
function y($m) 
{ 
	$m = preg_replace("/\./", " x ", $m); # remplace les points par des " x "
	$m = preg_replace("/@/", " y", $m); #remplace les @ par " y "
	return $m; 	
}

function x($y, $z) 
{ 
	$a = file_get_contents($y); # recupere le file de argv[1]
	$a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); #second groupe : tout ce qui est entre [x et ] et  applique y() au gorupe.
	$a = preg_replace("/\[/", "(", $a); # va remplacer tous les [ par des (
	$a = preg_replace("/\]/", ")", $a); # va remplacer des ] par des )
	return $a; 
}
$r = x($argv[1], $argv[2]); 
print $r;
?>
