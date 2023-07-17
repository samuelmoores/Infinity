//Maya ASCII 2023 scene
//Name: ANIM38_assign08_controlCurves.ma
//Last modified: Thu, Oct 13, 2022 03:33:08 PM
//Codeset: UTF-8
requires maya "2023";
requires "stereoCamera" "10.0";
requires "mtoa" "5.1.0";
requires "Mayatomr" "2012.0m - 3.9.1.36 ";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2023";
fileInfo "version" "2023";
fileInfo "cutIdentifier" "202202161415-df43006fd3";
fileInfo "osv" "Mac OS X 10.16";
fileInfo "UUID" "BC071024-854E-BA79-F058-ECB28B5AEF54";
createNode transform -n "clavicle_l_CRV";
	rename -uid "0FAD54AB-3A42-9641-B6CD-5B8517117BC2";
	setAttr ".ovc" 13;
	setAttr ".rp" -type "double3" 4.5338354110717791 144.39970397949219 3.7843434810638268 ;
	setAttr ".sp" -type "double3" 4.5338354110717791 144.39970397949219 3.7843434810638268 ;
createNode nurbsCurve -n "clavicle_l_CRVShape" -p "clavicle_l_CRV";
	rename -uid "FFC90421-C946-0DCC-EB1D-10B43208CD8B";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 6;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		15.722504902022566 147.17023486449398 -16.041578721739896
		14.265717196656682 145.77526219506939 -15.976750639828241
		13.56151007844125 147.66530756531884 -16.041578721739896
		14.846323375959297 155.32964413350663 -5.560315306582746
		13.561510078441254 147.66530756531884 5.0396145949920808
		14.265717196656682 145.77526219506939 4.7374535402450899
		15.722504902022566 147.17023486449395 5.0396145949920799
		17.902431563686058 154.62950560563939 -5.5603153065827389
		15.722504902022566 147.17023486449398 -16.041578721739896
		14.265717196656682 145.77526219506939 -15.976750639828241
		13.56151007844125 147.66530756531884 -16.041578721739896
		;
createNode transform -n "clavicle_r_CRV";
	rename -uid "F4B8A490-A349-BF2C-2E39-53B900D5F798";
	setAttr ".ovc" 13;
	setAttr ".rp" -type "double3" -4.53384 144.4 3.7843399999999807 ;
	setAttr ".sp" -type "double3" -4.53384 144.4 3.7843399999999807 ;
createNode nurbsCurve -n "clavicle_r_CRVShape" -p "clavicle_r_CRV";
	rename -uid "35869C32-6E4E-A02E-E0C8-469806C66B7A";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 13;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		-15.722504902022592 147.17023486449398 -16.041578721739917
		-14.265717196656704 145.77526219506942 -15.976750639828259
		-13.561510078441271 147.66530756531887 -16.041578721739917
		-14.846323375959321 155.32964413350669 -5.5603153065827708
		-13.56151007844127 147.66530756531887 5.0396145949920559
		-14.265717196656697 145.77526219506942 4.7374535402450668
		-15.722504902022578 147.17023486449395 5.0396145949920568
		-17.902431563686079 154.62950560563942 -5.5603153065827584
		-15.722504902022592 147.17023486449398 -16.041578721739917
		-14.265717196656704 145.77526219506942 -15.976750639828259
		-13.561510078441271 147.66530756531887 -16.041578721739917
		;
createNode transform -n "upperarm_l_CRV";
	rename -uid "2C5A395F-9B46-2159-2102-89B54029FC2B";
	setAttr ".rp" -type "double3" 20.296287536621094 140.24972534179688 -5.6301269531250107 ;
	setAttr ".sp" -type "double3" 20.296287536621094 140.24972534179688 -5.6301269531250107 ;
createNode nurbsCurve -n "upperarm_l_CRVShape" -p "upperarm_l_CRV";
	rename -uid "2B1E14C7-164B-DC77-C54A-A08627AD7816";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 6;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		18.695798451639998 132.58150151829022 2.617669368762388
		18.100914748318925 128.9783012679971 -5.5346587692943805
		20.142150173248442 131.44115370904638 -13.571974838128483
		22.355850836950129 138.94647872982577 -17.076479690208956
		22.498357985337115 147.41076686064764 -14.212120127745786
		21.433095791944194 151.56274477284305 -6.4399609197604191
		21.052006263728664 148.55111466989155 1.9775240791450788
		20.310400616289769 140.55917406748082 5.8191347171711163
		18.695798451639998 132.58150151829022 2.617669368762388
		18.100914748318925 128.9783012679971 -5.5346587692943805
		20.142150173248442 131.44115370904638 -13.571974838128483
		;
createNode transform -n "upperarm_r_CRV";
	rename -uid "B36028F9-4E40-AB1D-99F8-0BA210456072";
	setAttr ".rp" -type "double3" -20.296287536621094 140.24972534179688 -5.6301269531250107 ;
	setAttr ".sp" -type "double3" -20.296287536621094 140.24972534179688 -5.6301269531250107 ;
createNode nurbsCurve -n "upperarm_r_CRVShape" -p "upperarm_r_CRV";
	rename -uid "396E20FF-A04B-3101-5540-8A8E0F436E28";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 13;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		-18.695798451639998 132.58150151829022 2.6176693687623884
		-18.100914748318925 128.9783012679971 -5.5346587692943796
		-20.142150173248442 131.44115370904638 -13.571974838128483
		-22.355850836950125 138.94647872982577 -17.076479690208956
		-22.498357985337112 147.41076686064764 -14.212120127745786
		-21.433095791944194 151.56274477284305 -6.4399609197604191
		-21.052006263728664 148.55111466989155 1.9775240791450788
		-20.310400616289769 140.55917406748082 5.8191347171711163
		-18.695798451639998 132.58150151829022 2.6176693687623884
		-18.100914748318925 128.9783012679971 -5.5346587692943796
		-20.142150173248442 131.44115370904638 -13.571974838128483
		;
createNode transform -n "lowerarm_l_CRV";
	rename -uid "B78D603F-EF41-5BA0-72C7-8BA9BFADE027";
	setAttr ".rp" -type "double3" 37.853775024414062 121.38767242431641 -4.4554944038391113 ;
	setAttr ".sp" -type "double3" 37.853775024414062 121.38767242431641 -4.4554944038391113 ;
createNode nurbsCurve -n "lowerarm_l_CRVShape" -p "lowerarm_l_CRV";
	rename -uid "5E4FA587-F04E-E561-E7EF-A2928FC06E5F";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 6;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		31.793483391462576 118.5824105568329 2.7111354090018676
		30.928760954664476 115.77490049580651 -3.48619823366688
		35.048513156930532 115.32738079136493 -8.9510101993323712
		40.737228449025373 118.50421899970519 -11.041546522533345
		43.91406665736563 124.19293429180003 -8.9510101993323747
		43.46654695292407 128.3126864940661 -3.4861982336668866
		40.659036891897678 127.447964057268 2.7111354090018551
		36.133921208772477 123.10752623995812 5.4512179631427564
		31.793483391462576 118.5824105568329 2.7111354090018676
		30.928760954664476 115.77490049580651 -3.48619823366688
		35.048513156930532 115.32738079136493 -8.9510101993323712
		;
createNode transform -n "lowerarm_r_CRV";
	rename -uid "19F8E51D-8140-6246-2990-C6AABC47DF2E";
	setAttr ".rp" -type "double3" -37.853801727294922 121.38800048828125 -4.4554901123046875 ;
	setAttr ".sp" -type "double3" -37.853801727294922 121.38800048828125 -4.4554901123046875 ;
createNode nurbsCurve -n "lowerarm_r_CRVShape" -p "lowerarm_r_CRV";
	rename -uid "B4B4C788-3B40-7739-A69D-85A9FB8F4F54";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 13;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		-31.793534163796284 118.58239784707411 2.7111350505729606
		-30.92881172699818 115.77488778604771 -3.4861985920957936
		-35.048563929264262 115.32736808160614 -8.9510105577612791
		-40.737279221359088 118.5042062899464 -11.041546880962255
		-43.91411742969936 124.19292158204122 -8.9510105577612737
		-43.466597725257799 128.31267378430732 -3.4861985920957781
		-40.659087664231386 127.4479513475092 2.7111350505729597
		-36.133971981106193 123.10751353019931 5.4512176047138556
		-31.793534163796284 118.58239784707411 2.7111350505729606
		-30.92881172699818 115.77488778604771 -3.4861985920957936
		-35.048563929264262 115.32736808160614 -8.9510105577612791
		;
createNode transform -n "hand_l_CTRL";
	rename -uid "CA9BA5BA-CB48-7E6A-1AD8-10848A0175C8";
	setAttr ".rp" -type "double3" 53.644943237304688 104.43260192871094 6.6504960060119629 ;
	setAttr ".sp" -type "double3" 53.644943237304688 104.43260192871094 6.6504960060119629 ;
createNode nurbsCurve -n "hand_l_CTRLShape" -p "hand_l_CTRL";
	rename -uid "B1F14E7C-004E-900C-BDFC-22A36FC803BB";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 6;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		63.152051910536265 99.480796119848151 5.00020811636315
		58.354863593680399 101.98101098871473 2.11891801160214
		52.283083411871743 100.18032017999955 2.2561124760171918
		49.791986668406238 99.69750954642025 7.6547474821137644
		50.595452167271134 101.87222008909623 13.173458923005498
		56.386147374333461 103.95470684390079 14.854613141199566
		61.464420665935684 101.17269602894477 15.917554563351473
		63.531957518156361 98.947058614385057 11.001058464698005
		63.152051910536265 99.480796119848151 5.00020811636315
		58.354863593680399 101.98101098871473 2.11891801160214
		52.283083411871743 100.18032017999955 2.2561124760171918
		;
createNode transform -n "hand_r_CTRL";
	rename -uid "7CE801B3-4244-791B-5EC5-93B582648A72";
	setAttr ".rp" -type "double3" -53.644901275634766 104.43299865722656 6.6504998207092285 ;
	setAttr ".sp" -type "double3" -53.644901275634766 104.43299865722656 6.6504998207092285 ;
createNode nurbsCurve -n "hand_r_CTRLShape" -p "hand_r_CTRL";
	rename -uid "DC485AF4-C349-DBD6-0976-4FA7A75AA32E";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 13;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		-63.152049736281583 99.480735758353404 5.0002072586561139
		-58.354861419425724 101.98095062721998 2.1189171538951057
		-52.283081237617061 100.18025981850482 2.2561116183101539
		-49.791984494151563 99.697449184925517 7.6547466244067222
		-50.595449993016452 101.8721597276015 13.173458065298462
		-56.386145200078808 103.95464648240606 14.854612283492536
		-61.464418491681016 101.17263566745004 15.917553705644433
		-63.531955343901679 98.946998252890324 11.001057606990969
		-63.152049736281583 99.480735758353404 5.0002072586561139
		-58.354861419425724 101.98095062721998 2.1189171538951057
		-52.283081237617061 100.18025981850482 2.2561116183101539
		;
createNode transform -n "arm_l_CTRL";
	rename -uid "E9AD8345-E548-3659-0516-B9BB11E19B1F";
	setAttr ".rp" -type "double3" 53.644943237304688 104.43260192871094 6.6504960060119629 ;
	setAttr ".sp" -type "double3" 53.644943237304688 104.43260192871094 6.6504960060119629 ;
createNode nurbsCurve -n "arm_l_CTRLShape" -p "arm_l_CTRL";
	rename -uid "F93D1EB2-F94E-4BB7-5039-8DAC80DF05DA";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 6;
	setAttr ".cc" -type "nurbsCurve" 
		1 24 0 no 3
		25 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
		25
		46.178538727300442 96.966197418706699 6.6504960060119425
		48.710445718604383 101.13881692618206 10.980268137945844
		48.953988982846482 100.89527366193995 9.694867035629267
		50.820872287981352 102.76215696707483 9.6948670356292705
		50.332867169335813 103.25016208572038 12.270517482769213
		49.442287164067046 102.3595820804516 12.270517482769213
		51.71249555167622 106.3650496143394 16.849794241608464
		55.717963085564016 108.63525800194856 12.270517482769229
		54.827383080295249 107.7446779966798 12.270517482769227
		55.315388198940788 107.25667287803427 9.694867035629283
		57.182271504075658 109.12355618316914 9.6948670356292883
		56.938728239833551 109.36709944741123 10.980268137945865
		61.11134774730894 111.89900643871518 6.6504960060119833
		58.579440756004992 107.72638693123982 2.3207238740780856
		58.335897491762893 107.96993019548192 3.6061249763946588
		56.469014186628016 106.10304689034704 3.6061249763946543
		56.957019305273555 105.61504177170151 1.0304745292547102
		57.847599310542321 106.50562177697027 1.0304745292547128
		55.577390922933162 102.50015424308248 -3.5488022295845418
		51.571923389045359 100.22994585547332 1.0304745292546968
		52.462503394314133 101.12052586074208 1.0304745292546995
		51.974498275668587 101.60853097938761 3.6061249763946437
		50.107614970533717 99.741647674252732 3.6061249763946388
		50.351158234775824 99.49810441001064 2.3207238740780634
		46.178538727300442 96.966197418706699 6.6504960060119425
		;
createNode transform -n "arm_r_CTRL";
	rename -uid "63A36F50-EB45-8327-44A3-ABA21235BD32";
	setAttr ".rp" -type "double3" -53.644901275634766 104.43299865722656 6.6504998207092285 ;
	setAttr ".sp" -type "double3" -53.644901275634766 104.43299865722656 6.6504998207092285 ;
createNode nurbsCurve -n "arm_r_CTRLShape" -p "arm_r_CTRL";
	rename -uid "16426FB1-D94E-D19C-87BB-03BB0FAB692D";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 13;
	setAttr ".cc" -type "nurbsCurve" 
		1 24 0 no 3
		25 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
		25
		-46.178496765630513 96.966594147222324 6.6504998207092063
		-48.710403756934454 101.13921365469768 10.980271952643108
		-48.953947021176553 100.89567039045558 9.6948708503265344
		-50.82083032631143 102.76255369559046 9.6948708503265344
		-50.332825207665891 103.250558814236 12.270521297466484
		-49.442245202397125 102.35997880896723 12.270521297466482
		-51.712453590006305 106.36544634285502 16.849798056305737
		-55.717921123894094 108.63565473046418 12.270521297466495
		-54.827341118625327 107.74507472519542 12.270521297466493
		-55.315346237270866 107.25706960654989 9.6948708503265486
		-57.182229542405743 109.12395291168477 9.6948708503265539
		-56.938686278163637 109.36749617592686 10.980271952643132
		-61.111305785639026 111.8994031672308 6.6504998207092498
		-58.579398794335077 107.72678365975544 2.3207276887753512
		-58.335855530092978 107.97032692399755 3.6061287910919253
		-56.468972224958094 106.10344361886267 3.6061287910919195
		-56.956977343603633 105.61543850021714 1.0304783439519749
		-57.847557348872407 106.5060185054859 1.0304783439519776
		-55.577348961263233 102.5005509715981 -3.548798414887278
		-51.571881427375438 100.23034258398894 1.0304783439519589
		-52.462461432644211 101.1209225892577 1.0304783439519607
		-51.974456313998665 101.60892770790323 3.6061287910919071
		-50.107573008863788 99.742044402768357 3.6061287910919018
		-50.351116273105895 99.498501138526265 2.3207276887753263
		-46.178496765630513 96.966594147222324 6.6504998207092063
		;
createNode transform -n "armTwist_l_CTRL";
	rename -uid "2DC6D336-634B-E2EF-9D5C-D59243ABC561";
	setAttr ".rp" -type "double3" 37.853775024414062 121.38767242431641 -27.085756131423938 ;
	setAttr ".sp" -type "double3" 37.853775024414062 121.38767242431641 -27.085756131423938 ;
createNode nurbsCurve -n "armTwist_l_CTRLShape" -p "armTwist_l_CTRL";
	rename -uid "58F75673-124C-595D-3E41-D9A8DB3309E8";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 6;
	setAttr ".cc" -type "nurbsCurve" 
		1 6 0 no 3
		7 0 1 2 3 4 5 6
		7
		37.853828605679098 121.38772195432834 -27.085756130566146
		36.428347040059919 122.92979922414328 -30.085756131423938
		39.279310171298278 119.8456446845134 -30.085756131423938
		37.853828605679098 121.38772195432834 -27.085756130566146
		39.460550891911893 122.87296075845727 -30.085756131423938
		36.255414090937812 119.91016277517303 -30.085756131423938
		37.853828605679098 121.38772195432834 -27.085756130566146
		;
createNode transform -n "armTwist_r_CTRL";
	rename -uid "34FEB519-E84A-2834-9678-0B98B1A6D42E";
	setAttr ".rp" -type "double3" -37.853801727294922 121.38800048828125 -27.085756131423931 ;
	setAttr ".sp" -type "double3" -37.853801727294922 121.38800048828125 -27.085756131423931 ;
createNode nurbsCurve -n "armTwist_r_CTRLShape" -p "armTwist_r_CTRL";
	rename -uid "C9B8FF76-6445-22EB-CB0F-CBA663911E43";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 13;
	setAttr ".cc" -type "nurbsCurve" 
		1 6 0 no 3
		7 0 1 2 3 4 5 6
		7
		-37.853855308559957 121.38805001829319 -27.085756130566139
		-36.428373742940771 122.93012728810812 -30.085756131423931
		-39.27933687417913 119.84597274847825 -30.085756131423931
		-37.853855308559957 121.38805001829319 -27.085756130566139
		-39.460577594792746 122.87328882242211 -30.085756131423931
		-36.255440793818664 119.91049083913788 -30.085756131423931
		-37.853855308559957 121.38805001829319 -27.085756130566139
		;
select -ne :time1;
	setAttr -av -k on ".cch";
	setAttr -k on ".fzn";
	setAttr -av -cb on ".ihi";
	setAttr -av -k on ".nds";
	setAttr -cb on ".bnm";
	setAttr -k on ".o" 0;
	setAttr -av -k on ".unw";
	setAttr -av -k on ".etw";
	setAttr -av -k on ".tps";
	setAttr -av -k on ".tms";
select -ne :hardwareRenderingGlobals;
	setAttr -av -k on ".ihi";
	setAttr ".otfna" -type "stringArray" 22 "NURBS Curves" "NURBS Surfaces" "Polygons" "Subdiv Surface" "Particles" "Particle Instance" "Fluids" "Strokes" "Image Planes" "UI" "Lights" "Cameras" "Locators" "Joints" "IK Handles" "Deformers" "Motion Trails" "Components" "Hair Systems" "Follicles" "Misc. UI" "Ornaments"  ;
	setAttr ".otfva" -type "Int32Array" 22 0 1 1 1 1 1
		 1 1 1 0 0 0 0 0 0 0 0 0
		 0 0 0 0 ;
	setAttr -k on ".hwi";
	setAttr -av ".ta";
	setAttr -av ".tq";
	setAttr -av ".etmr";
	setAttr -av ".tmr";
	setAttr -av ".aoon";
	setAttr -av ".aoam";
	setAttr -av ".aora";
	setAttr -k on ".hff";
	setAttr -av -k on ".hfd";
	setAttr -av -k on ".hfs";
	setAttr -av -k on ".hfe";
	setAttr -av ".hfc";
	setAttr -av -k on ".hfcr";
	setAttr -av -k on ".hfcg";
	setAttr -av -k on ".hfcb";
	setAttr -av -k on ".hfa";
	setAttr -av ".mbe";
	setAttr -av -k on ".mbsof";
	setAttr -k on ".blen";
	setAttr -k on ".blat";
	setAttr -av ".msaa" yes;
	setAttr ".fprt" yes;
select -ne :renderPartition;
	setAttr -av -k on ".cch";
	setAttr -cb on ".ihi";
	setAttr -av -k on ".nds";
	setAttr -cb on ".bnm";
	setAttr -s 2 ".st";
	setAttr -cb on ".an";
	setAttr -cb on ".pt";
select -ne :renderGlobalsList1;
	setAttr -k on ".cch";
	setAttr -cb on ".ihi";
	setAttr -k on ".nds";
	setAttr -cb on ".bnm";
select -ne :defaultShaderList1;
	setAttr -k on ".cch";
	setAttr -cb on ".ihi";
	setAttr -k on ".nds";
	setAttr -cb on ".bnm";
	setAttr -s 5 ".s";
select -ne :postProcessList1;
	setAttr -k on ".cch";
	setAttr -cb on ".ihi";
	setAttr -k on ".nds";
	setAttr -cb on ".bnm";
	setAttr -s 2 ".p";
select -ne :defaultRenderingList1;
	setAttr -k on ".ihi";
select -ne :initialShadingGroup;
	setAttr -av -k on ".cch";
	setAttr -k on ".fzn";
	setAttr -cb on ".ihi";
	setAttr -av -k on ".nds";
	setAttr -cb on ".bnm";
	setAttr -k on ".bbx";
	setAttr -k on ".vwm";
	setAttr -k on ".tpv";
	setAttr -k on ".uit";
	setAttr -k on ".mwc";
	setAttr -cb on ".an";
	setAttr -cb on ".il";
	setAttr -cb on ".vo";
	setAttr -cb on ".eo";
	setAttr -cb on ".fo";
	setAttr -cb on ".epo";
	setAttr -k on ".ro" yes;
	setAttr -k on ".ai_surface_shader";
	setAttr -k on ".ai_volume_shader";
select -ne :initialParticleSE;
	setAttr -av -k on ".cch";
	setAttr -cb on ".ihi";
	setAttr -av -k on ".nds";
	setAttr -cb on ".bnm";
	setAttr -k on ".mwc";
	setAttr -cb on ".an";
	setAttr -cb on ".il";
	setAttr -cb on ".vo";
	setAttr -cb on ".eo";
	setAttr -cb on ".fo";
	setAttr -cb on ".epo";
	setAttr -k on ".ro" yes;
	setAttr -k on ".ai_surface_shader";
	setAttr -k on ".ai_volume_shader";
select -ne :defaultRenderGlobals;
	addAttr -ci true -h true -sn "dss" -ln "defaultSurfaceShader" -dt "string";
	setAttr -av -k on ".cch";
	setAttr -cb on ".ihi";
	setAttr -av -k on ".nds";
	setAttr -cb on ".bnm";
	setAttr -av -k on ".macc";
	setAttr -av -k on ".macd";
	setAttr -av -k on ".macq";
	setAttr -av -k on ".mcfr";
	setAttr -cb on ".ifg";
	setAttr -av -k on ".clip";
	setAttr -av -k on ".edm";
	setAttr -av -k on ".edl";
	setAttr -av -cb on ".ren" -type "string" "arnold";
	setAttr -av -k on ".esr";
	setAttr -av -k on ".ors";
	setAttr -cb on ".sdf";
	setAttr -av -k on ".outf";
	setAttr -av -cb on ".imfkey";
	setAttr -av -k on ".gama";
	setAttr -k on ".exrc";
	setAttr -k on ".expt";
	setAttr -av -cb on ".an";
	setAttr -cb on ".ar";
	setAttr -av -k on ".fs";
	setAttr -av -k on ".ef";
	setAttr -av -k on ".bfs";
	setAttr -av -cb on ".me";
	setAttr -cb on ".se";
	setAttr -av -k on ".be";
	setAttr -av -cb on ".ep";
	setAttr -av -k on ".fec";
	setAttr -av -k on ".ofc";
	setAttr -cb on ".ofe";
	setAttr -cb on ".efe";
	setAttr -cb on ".oft";
	setAttr -cb on ".umfn";
	setAttr -cb on ".ufe";
	setAttr -av -cb on ".pff";
	setAttr -av -k on ".peie";
	setAttr -av -cb on ".ifp";
	setAttr -k on ".rv";
	setAttr -av -k on ".comp";
	setAttr -av -k on ".cth";
	setAttr -av -k on ".soll";
	setAttr -cb on ".sosl";
	setAttr -av -k on ".rd";
	setAttr -av -k on ".lp";
	setAttr -av -k on ".sp";
	setAttr -av -k on ".shs";
	setAttr -av -k on ".lpr";
	setAttr -cb on ".gv";
	setAttr -cb on ".sv";
	setAttr -av -k on ".mm";
	setAttr -av -k on ".npu";
	setAttr -av -k on ".itf";
	setAttr -av -k on ".shp";
	setAttr -cb on ".isp";
	setAttr -av -k on ".uf";
	setAttr -av -k on ".oi";
	setAttr -av -k on ".rut";
	setAttr -av -k on ".mot";
	setAttr -av -k on ".mb";
	setAttr -av -k on ".mbf";
	setAttr -av -k on ".mbso";
	setAttr -av -k on ".mbsc";
	setAttr -av -k on ".afp";
	setAttr -av -k on ".pfb";
	setAttr -k on ".pram";
	setAttr -k on ".poam";
	setAttr -k on ".prlm";
	setAttr -k on ".polm";
	setAttr -cb on ".prm";
	setAttr -cb on ".pom";
	setAttr -cb on ".pfrm";
	setAttr -cb on ".pfom";
	setAttr -av -k on ".bll";
	setAttr -av -k on ".bls";
	setAttr -av -k on ".smv";
	setAttr -av -k on ".ubc";
	setAttr -av -k on ".mbc";
	setAttr -cb on ".mbt";
	setAttr -av -k on ".udbx";
	setAttr -av -k on ".smc";
	setAttr -av -k on ".kmv";
	setAttr -cb on ".isl";
	setAttr -cb on ".ism";
	setAttr -cb on ".imb";
	setAttr -av -k on ".rlen";
	setAttr -av -k on ".frts";
	setAttr -av -k on ".tlwd";
	setAttr -av -k on ".tlht";
	setAttr -av -k on ".jfc";
	setAttr -cb on ".rsb";
	setAttr -av -cb on ".ope";
	setAttr -av -cb on ".oppf";
	setAttr -av -k on ".rcp";
	setAttr -av -k on ".icp";
	setAttr -av -k on ".ocp";
	setAttr -cb on ".hbl";
	setAttr ".dss" -type "string" "lambert1";
select -ne :defaultResolution;
	setAttr -av -k on ".cch";
	setAttr -av -k on ".ihi";
	setAttr -av -k on ".nds";
	setAttr -k on ".bnm";
	setAttr -av -k on ".w";
	setAttr -av -k on ".h";
	setAttr -av -k on ".pa" 1;
	setAttr -av -k on ".al";
	setAttr -av -k on ".dar";
	setAttr -av -k on ".ldar";
	setAttr -av -k on ".dpi";
	setAttr -av -k on ".off";
	setAttr -av -k on ".fld";
	setAttr -av -k on ".zsl";
	setAttr -av -k on ".isu";
	setAttr -av -k on ".pdu";
select -ne :defaultColorMgtGlobals;
	setAttr ".cfe" yes;
	setAttr ".cfp" -type "string" "<MAYA_RESOURCES>/OCIO-configs/Maya-legacy/config.ocio";
	setAttr ".vtn" -type "string" "sRGB gamma (legacy)";
	setAttr ".vn" -type "string" "sRGB gamma";
	setAttr ".dn" -type "string" "legacy";
	setAttr ".wsn" -type "string" "scene-linear Rec 709/sRGB";
	setAttr ".ovt" no;
	setAttr ".povt" no;
	setAttr ".otn" -type "string" "sRGB gamma (legacy)";
	setAttr ".potn" -type "string" "sRGB gamma (legacy)";
select -ne :hardwareRenderGlobals;
	setAttr -av -k on ".cch";
	setAttr -cb on ".ihi";
	setAttr -av -k on ".nds";
	setAttr -cb on ".bnm";
	setAttr -av -k off -cb on ".ctrs" 256;
	setAttr -av -k off -cb on ".btrs" 512;
	setAttr -av -k off -cb on ".fbfm";
	setAttr -av -k off -cb on ".ehql";
	setAttr -av -k off -cb on ".eams";
	setAttr -av -k off -cb on ".eeaa";
	setAttr -av -k off -cb on ".engm";
	setAttr -av -k off -cb on ".mes";
	setAttr -av -k off -cb on ".emb";
	setAttr -av -k off -cb on ".mbbf";
	setAttr -av -k off -cb on ".mbs";
	setAttr -av -k off -cb on ".trm";
	setAttr -av -k off -cb on ".tshc";
	setAttr -av -k off -cb on ".enpt";
	setAttr -av -k off -cb on ".clmt";
	setAttr -av -k off -cb on ".tcov";
	setAttr -av -k off -cb on ".lith";
	setAttr -av -k off -cb on ".sobc";
	setAttr -av -k off -cb on ".cuth";
	setAttr -av -k off -cb on ".hgcd";
	setAttr -av -k off -cb on ".hgci";
	setAttr -av -k off -cb on ".mgcs";
	setAttr -av -k off -cb on ".twa";
	setAttr -av -k off -cb on ".twz";
	setAttr -k on ".hwcc";
	setAttr -k on ".hwdp";
	setAttr -k on ".hwql";
	setAttr -k on ".hwfr";
	setAttr -k on ".soll";
	setAttr -k on ".sosl";
	setAttr -k on ".bswa";
	setAttr -k on ".shml";
	setAttr -k on ".hwel";
// End of ANIM38_assign08_controlCurves.ma
