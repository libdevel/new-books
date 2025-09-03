<?php

require_once('library/config.inc');

// example: SUNY%20Broome%20Community%20College%2001SUNY_BCC/Reports/New%20Books/new-print-titles-for-rss-v3
$analyticspath = "SUNY%20Broome%20Community%20College%2001SUNY_BCC/Reports/New%20Books/new-STEM-print-titles-for-rss-v3";


$apikey = $almaapikey;

//analytics API key:
//$apikey = "l8xx897808403f814d7da6beae47c475b048";

//  ex: https://suny-bcc.primo.exlibrisgroup.com
$primoroot = "https://suny-bcc.primo.exlibrisgroup.com";

// primo vid
// example:  01SUNY_BCC:01SUNY_BCC

$primovid = "01SUNY_BCC:01SUNY_BCC";

// retrieve data from API
$newbooks_url ="https://api-na.hosted.exlibrisgroup.com/almaws/v1/analytics/reports?path=/shared/".$analyticspath."&limit=200&apikey=".$apikey."";

// scan the xml and place records into an array
$xml = simplexml_load_file($newbooks_url);

// uncomment the line below to see the column data in the raw xml
//echo htmlspecialchars($xml->asXML());
// Output header information
header('Content-Type: application/xml; charset=utf-8');
echo '<?xml version="1.0" encoding="utf-8"?>' . PHP_EOL;
?>
<rss version="2.0">
<channel>
	<title>SUNY Broome Library New STEM Print Books</title>
	<link>http://www.sunybroome.edu/library/</link>
	<description>SUNY Broome Library Book Feed : New STEM Books</description>
<image>
	<url>https://sunybroome.info/ssl_images/sunybroomelibrarylogo.jpg</url>
	<title>SUNY Broome Library</title>
	<link>http://www.sunybroome.edu/library/</link>
</image>
<?php
	foreach ($xml->QueryResult->ResultXml->rowset->Row as $row){		
		$author = (string) $row->Column2;
		if (empty($author)) {
		$author = "author unknown";	
			}
		$isbns = (string) $row->Column3;
		$isbn_array = explode (';' , $isbns); //isbn for book covers
		$mms = (string) $row->Column4;
		$title_raw = (string) trim($row->Column7, " /");
		$title2 = preg_replace('/&(?![#]?[a-z0-9]+;)/i', "&amp;$1", $title_raw);
		
	// replace double quotes
		$title = preg_replace('/"(?![#]?[a-z0-9]+;)/i', "'", $title2);
		
		$pubdate_raw = (string) $row->Column5;
		preg_match ( '/\d{4}/', $pubdate_raw, $publication_date);
		$lc_code = (string) $row->Column8;

		$url ="".$primoroot."/discovery/fulldisplay?docid=alma".$mms."&amp;context=U&amp;vid=".$primovid."&amp;lang=en";
		$alt = "alt=\"".$title." by ".$author."\"";

	if (strlen($isbn_array[0]) > 0) {
		$trimmed_array = array_map('trim', $isbn_array);
		
		// check each isbn in syndetics for a cover
		foreach ($trimmed_array as $value){
		$image_s = 'https://syndetics.com/index.php?client=primo&isbn='.$value.'/mc.jpg';
		$image_size_s = getimagesize($image_s);
			if ($image_size_s[0] > 1 and $image_size_s[1] > 1) {
				$image_src = '<img class="book_cover" height="150" '. $alt . ' src="' . $image_s . '"/>';
				break;
			} 
		}
		
		if 	($image_size_s[0] < 2) {
			// check Open Library  for a cover
				$image_s2 = 'https://covers.openlibrary.org/b/isbn/'.$isbn_array[0].'-M.jpg';
				$image_size_o = getimagesize($image_s2);
				if ($image_size_o[0] > 1 and $image_size_o[1] > 1) {
					$image_src = '<img class="book_cover" height="150" '. $alt . ' src="' . $image_s2 . '"/>';
				} else {
					// check google books
					$image_s3 = 'https://books.google.com/books?vid=ISBN'.$isbn_array[0].'&printsec=frontcover&img=1&zoom=5&zoom=1';
					$image_size = getimagesize($image_s3);
					$image_src = '<img class="book_cover" height="150" '. $alt . ' src="' . $image_s3 . '"/>';
				}
			}	
	$description = "<a href=\"".$url."\">".$image_src."</a>";
?>
<item>
	<title><?php echo $title; ?></title>
	<pubDate><?php echo $publication_date[0]; ?></pubDate>
	<link><?php echo $url; ?></link>
	<description>
		<![CDATA[
			<?php echo $description; ?>
		]]>
	</description>
</item>
<?php
}}
?>
</channel>
</rss>
