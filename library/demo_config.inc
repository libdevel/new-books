<?php
//Local Settings
if (isset($_SERVER['HTTPS'])):
	define('SERVER', 'https://' . $_SERVER['HTTP_HOST']);
else:
	define('SERVER', 'http://' . $_SERVER['HTTP_HOST']);
endif;

//set_include_path(".:/usr/local/php5/lib/php:/usr/local/lib/php:/usr/local/ZendFrameworkCli/library");




$almaapikey = "insert key here";

// Search bases

$search_bases = "
<select name=\"collcode\" id=\"collcode\">
	<option value=\" and (wcl=circ or wcl=circo or wcl=newbk or wcl=JCIRC)\">Circ</option>
	<option value=\"\">All</option>
	<option value=\" and (wcl=circ or wcl=circo or wcl=eref or wcl=erefo or wcl=newbk or wcl=JCIRC)\">Circ and ref</option>
	<option value=\" and (wcl=eref or wcl=erefo)\">Reference</option>
	<option value=\" and (wcl=MEDAU or wcl=MEDCD or wcl=MEDVD or wcl=MNDVD or wcl=MEDVC or wcl=MEDVN)\">AV</option>
	<option value=\" and (wcl=ebook or wcl=ebry or wcl=gvrl or wcl=SPRCM)\">Ebooks</option>
</select>";

// canned queries

$subject_area = "
<select name=\"request\" id=\"request\">
	<option value=\"wlc=a*\">A - General Works</option>
	<option value=\"wlc=b1*->bd999.99*\">B-BD - Philosophy</option>
	<option value=\"wlc=bf*\">BF – Psychology</option>	
	<option value=\"wlc=bh1*->bj999.99*\">BH-BJ – Aesthetics. Ethics</option>	
	<option value=\"wlc=bl1*->bx999.99*\">BL-BX - Religion and Theology</option>		
	<option value=\"wlc=c*\">C - Auxiliary Sciences of History</option>
	<option value=\"wlc=d1*->d999.99*\">D - History - General</option>
	<option value=\"wlc=da1*->dr999.99*\">DA-DR - History - Europe</option>
	<option value=\"wlc=ds*\">DS – History - Asia</option>	
	<option value=\"wlc=dt1*->dx999.99*\">DT-DX – Africa. Oceania. Gypsies</option>
	<option value=\"wlc=e*\">E – American History</option>	
	<option value=\"wlc=f*\">F – Local History of the United States and South America</option>
	<option value=\"wlc=g1*->gc999.99*\">G-GC - Geography - Oceanography</option>
	<option value=\"wlc=ge*\">GE – Environmental Sciences</option>
	<option value=\"wlc=gf*\">GF – Human ecology. Anthropogeography</option>
	<option value=\"wlc=gn*\">GN – Anthropology</option>
	<option value=\"wlc=gr1*->gt999.99*\">GR-GT – Folklore. Manners and customs</option>	
	<option value=\"wlc=gv*\">GV – Recreation. Leisure</option>
	<option value=\"wlc=h1*->h999.99*\">H – Social sciences (General)</option>
	<option value=\"wlc=ha1*->hc999.99*\">HA-HC – Statistics. Economics</option>
	<option value=\"wlc=hd*\">HD – Industries. Land use. Labor</option>
	<option value=\"wlc=he*\">HE – Transportation and communications</option>
	<option value=\"wlc=hf*\">HF – Commerce</option>	
	<option value=\"wlc=hg1*->hj999.99*\">HG-HJ – Finance, Public finance</option>
	<option value=\"wlc=hm*\">HM – Sociology (General)</option>
	<option value=\"wlc=hn*\">HN – Social history and conditions.</option>
	<option value=\"wlc=hq*\">HQ – The family. Marriage. Women</option>
	<option value=\"wlc=hs1*->ht999.99*\">HS–HT - Societies. Communities. Classes. Races</option>
	<option value=\"wlc=hv*\">HV – Social pathology. Social and public welfare. Criminology</option>
	<option value=\"wlc=hx*\">HX – Socialism. Communism. Anarchism</option>
	<option value=\"wlc=j*\">J – Political Science</option>
	<option value=\"wlc=k*\">K - Law</option>
	<option value=\"wlc=l*\">L – Education </option>
	<option value=\"wlc=m*\">M - Music</option>
	<option value=\"wlc=n*\">N - Art</option>				
	<option value=\"wlc=p1*->p999.99*\">P - Philology</option>
	<option value=\"wlc=pa1*->pm999.99*\">PA-PM - Language and Lit</option>
	<option value=\"wlc=pn*\">PN – Literature (General)</option>
	<option value=\"wlc=pq*\">PQ – French, Italian, Spanish, Portuguese literature</option>
	<option value=\"wlc=pr*\">PR – English literature</option>										
	<option value=\"wlc=ps*\">PS – American literature</option>
	<option value=\"wlc=pt*\">PT – Other European literature</option>
	<option value=\"wlc=pz5*->pz90.999*\">PZ - Juv Fiction</option>										
	<option value=\"wlc=q1*->q999.99*\">Q – Science (General)</option>			
	<option value=\"wlc=qa1->qa433\">QA – Mathematics pt 1</option>
	<option value=\"wlc=qa440*->qa999.99*\">QA – Mathematics pt 2</option>					
	<option value=\"wlc=qb*\">QB – Astronomy</option>			
	<option value=\"wlc=qc*\">QC – Physics</option>
	<option value=\"wlc=qd*\">QD – Chemistry</option>
	<option value=\"wlc=qe*\">QE – Geology</option>					
	<option value=\"wlc=qh*\">QH – Natural history – Biology</option>
	<option value=\"wlc=qk*\">QK – Botany</option>
	<option value=\"wlc=ql*\">QL – Zoology</option>
	<option value=\"wlc=qm1->qp999.99*\">QM-QP – Human anatomy. Physiology</option>
	<option value=\"wlc=qr*\">QR – Microbiology</option>
	<option value=\"wlc=r1*->r999.99*\">R – Medicine (General)</option>
	<option value=\"wlc=ra1*->rd999.99*\">RA-RD – Medicine. Surgery</option>
	<option value=\"wlc=rg1*->rj999.99*\">RG-RJ – Gynecology and Obstetrics. Pediatrics</option>
	<option value=\"wlc=rk*\">RK – Dentistry</option>
	<option value=\"wlc=rl*\">RL – Dermatology</option>	
	<option value=\"wlc=rm1*->rs999.99*\">RM-RS – Therapeutics. Pharmacology. Pharmacy</option>					
	<option value=\"wlc=rt*\">RT – Nursing</option>
	<option value=\"wlc=rx1*->rz999.99*\">RX-RZ - Homopathy Other Systems of Medicine</option>
	<option value=\"wlc=s*\">S – Agriculture</option>
	<option value=\"wlc=t1*->t999.99*\">T – Technology (General)</option>
	<option value=\"wlc=ta*\">TA – Engineering. Civil engineering (General) </option>
	<option value=\"wlc=tc*\">TC – Hydraulic engineering. Ocean engineering </option>
	<option value=\"wlc=td*\">TD – Environmental technology. Sanitary engineering </option>
	<option value=\"wlc=te1*->tg999.99*\">TE TF TG - Roads, Railroads, Bridges</option>
	<option value=\"wlc=th*\">TH – Building construction</option>
	<option value=\"wlc=tj*\">TJ – Mechanical engineering and machinery</option>
	<option value=\"wlc=tk*\">TK – Electrical engineering. Electronics. Nuclear engineering </option>
	<option value=\"wlc=tl*\">TL – Motor vehicles. Aeronautics. Astronautics</option>
	<option value=\"wlc=tn*\">TN – Mining engineering. Metallurgy </option>
	<option value=\"wlc=tp*\">TP – Chemical technology</option>				
	<option value=\"wlc=tr*\">TR – Photography</option>
	<option value=\"wlc=ts*\">TS – Manufacturing engineering. Mass production</option>
	<option value=\"wlc=tt1*->tx999.99*\">TT-TX – Handicrafts. Home economics</option>
	<option value=\"wlc=u*\">U – Military Science</option>
	<option value=\"wlc=v*\">V – Naval Science</option>
	<option value=\"wlc=z*\">Z - Library Science</option>

</select>";

//OCLC Settings
$local_oclc = "YSY";
$WorldCat_API_Key = '';


// Holdings strings
$ids_libraries = 'BNG,BUF,CTX,NYG,NYP,RVE,SYB,UVV,VDB,VDH,VGA,VGK,VGN,VJA,VJN,VND,VQT,VSI,VVB,VVJ,VVO,VVV,VVX,VXF,VXP,VXT,VXV,VYA,VYE,VYL,VYQ,VYT,VZB,VZJ,WKM,XBM,XDM,XFM,XJM,XMM,XQM,XNC,YAH,YBM,YCM,YDM,YGM,YJA,YJL,YJM,YOM,YPM,YSM,YSY,YTM,ZBM,ZDG,ZEM,ZGM,ZHM,ZLM,ZMM,ZOW,ZPM,ZQM,ZRS,ZVM,ZXC,ZZY';

$suny_libraries = 'BNG,BUF,COO,NAM,SBH,UVV,VDH,VDN,VGA,VGK,VGN,VJK,VOC,VQT,VVD,VVR,VVX,VXF,VXH,VXP,VXT,VXV,VYQ,VZB,WCC,WKM,XBM,XDM,XFM,XJM,XMM,YBM,YCM,YDD,YDM,YEM,YFM,YGM,YJA,YJL,YJM,YKJ,YKU,YLC,YOM,YPM,YSM,YSY,YTM,ZAM,ZBM,ZCM,ZDG,ZFM,ZLM,ZMM,ZNO,ZOW,ZPM,ZQM,ZVM,ZZY';

$cc_libraries = 'VJK,YSY,ZZY,YLC,VDH,ZDG,VDN,YJL,UVV,ZFM,YJM,YJA,VXH,VXV,YKJ,VND,ZVM,VQT,VVX,YKU,ZNO,VOC,VGA,VVR,XJM,YDD,VGK,VXT,VGN,WCC';


?>
