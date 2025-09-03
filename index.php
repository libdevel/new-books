<?php 
//	require_once('library/config.inc');
	require_once('library/header.inc');
?>
	

<div class="container mt-5">

<h2>New Books</h2>

<h3>Print</h3>
<ul>
    <li><a href="alma_new_print_books_to_rss.php">*alma_new_print_books_to_rss.php</a></li>
    <li><a href="alma_print_books_to_rss_v6a.php">*alma_print_books_to_rss_v6a.php</a></li>
    <li><a href="alma_print_books_to_rss_v7.php">*alma_print_books_to_rss_v7.php</a></li>
</ul>

<h3>eBooks</h3>
<ul>
    <li><a href="alma_new_elec_books_to_rss.php">*alma_new_elec_books_to_rss.php</a></li>
    <li><a href="alma_elec_books_to_rss_v4.php">*alma_elec_books_to_rss_v4.php</a></li>
    <li><a href="alma_elec_books_to_rss_v4a.php">*alma_elec_books_to_rss_v4a.php</a></li>
</ul>




<h2>Books on Display</h2>
<ul>
		<li><a href="alma_display_print_books_to_rss.php">*alma_display_print_books_to_rss.php</a></li>
		<li><a href="alma_display_elec_books_to_rss.php">*alma_display_elec_books_to_rss.php</a></li>
</ul>

<h2>New Books by Division</h2>
 <ul>
 	<li><a href="alma_div_HS_print_books_to_rss.php">alma_div_HS_print_books_to_rss.php</a></li>
 	<li><a href="alma_div_STEM_print_books_to_rss.php">alma_div_STEM_print_books_to_rss.php</a></li>
 </ul>

</div><!--div mt-5-->

<footer>
	<div class="mt-5 p-4 bg-dark text-white text-center">
<a href="http://librarydev.com">Libdevel.com</a><br />
Last updated: <?php print date ("F d, Y", getlastmod()); ?><br />
	</div>
</footer>

</div><!--div wrap-->
</body>
</html>
