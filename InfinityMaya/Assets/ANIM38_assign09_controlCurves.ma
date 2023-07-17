//Maya ASCII 2023 scene
//Name: ANIM38_assign09_controlCurves.ma
//Last modified: Wed, Oct 19, 2022 01:43:46 PM
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
fileInfo "UUID" "6BDB9C3C-FF44-860F-EDF0-F38898465B5C";
createNode transform -n "ANIM38_thumb_l_CTRL";
	rename -uid "9CFB6A01-4049-BB49-E225-969F17A74C21";
	addAttr -ci true -sn "bend" -ln "bend" -at "double";
	addAttr -ci true -sn "curl" -ln "curl" -at "double";
	addAttr -ci true -sn "spread" -ln "spread" -at "double";
	setAttr ".rp" -type "double3" 54.584559111091231 101.03528503696113 16.863881459127569 ;
	setAttr ".sp" -type "double3" 54.584559111091231 101.03528503696113 16.863881459127569 ;
	setAttr -k on ".bend";
	setAttr -k on ".curl";
	setAttr -k on ".spread";
createNode nurbsCurve -n "ANIM38_thumb_l_CTRLShape" -p "ANIM38_thumb_l_CTRL";
	rename -uid "913D8043-7A47-569F-5A08-AD86D336587C";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 6;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		56.309365402905257 101.4636338781583 16.433710081891817
		55.37492137868653 102.20083347755568 15.697557659139633
		53.977493857298434 102.25527060805547 15.644621900301772
		52.935676928336697 101.59505673690762 16.305911854970958
		52.859752819277233 100.60693619576372 17.294052836363122
		53.794196843495961 99.869736596366337 18.03020525911532
		55.191624364884049 99.815299465866516 18.083141017953153
		56.233441293845793 100.47551333701433 17.421851063283981
		56.309365402905257 101.4636338781583 16.433710081891817
		55.37492137868653 102.20083347755568 15.697557659139633
		53.977493857298434 102.25527060805547 15.644621900301772
		;
createNode transform -n "ANIM38_index_l_CTRL";
	rename -uid "1E1337D1-D542-A1A1-176C-2596BB55CA91";
	addAttr -ci true -sn "bend" -ln "bend" -at "double";
	addAttr -ci true -sn "curl" -ln "curl" -at "double";
	addAttr -ci true -sn "spread" -ln "spread" -at "double";
	setAttr ".rp" -type "double3" 64.353689015791176 98.08259155917645 14.050570425962954 ;
	setAttr ".sp" -type "double3" 64.353689015791176 98.08259155917645 14.050570425962954 ;
	setAttr -k on ".bend";
	setAttr -k on ".curl";
	setAttr -k on ".spread";
createNode nurbsCurve -n "ANIM38_index_l_CTRLShape" -p "ANIM38_index_l_CTRL";
	rename -uid "2EF33C0E-CA41-4591-7622-27BFC5C56572";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 6;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		65.315487426796011 97.049903237200581 13.553880771877049
		64.794416419506391 97.60938008597806 12.701484726876137
		64.015173276429891 98.446057797884592 12.639364787596698
		63.43422806239446 99.069821916620626 13.403909971974832
		63.391890604786333 99.115279881152276 14.547260080048869
		63.912961612075947 98.555803032374797 15.399656125049781
		64.692204755152446 97.719125320468265 15.46177606432922
		65.27314996918787 97.095361201732231 14.697230879951086
		65.315487426796011 97.049903237200581 13.553880771877049
		64.794416419506391 97.60938008597806 12.701484726876137
		64.015173276429891 98.446057797884592 12.639364787596698
		;
createNode transform -n "ANIM38_middle_l_CTRL";
	rename -uid "591CEC03-EC4C-49C8-0A10-588B30106CB5";
	addAttr -ci true -sn "bend" -ln "bend" -at "double";
	addAttr -ci true -sn "curl" -ln "curl" -at "double";
	addAttr -ci true -sn "spread" -ln "spread" -at "double";
	setAttr ".rp" -type "double3" 65.301382131702098 97.065048171268856 10.452365623318483 ;
	setAttr ".sp" -type "double3" 65.301382131702098 97.065048171268856 10.452365623318483 ;
	setAttr -k on ".bend";
	setAttr -k on ".curl";
	setAttr -k on ".spread";
createNode nurbsCurve -n "ANIM38_middle_l_CTRLShape" -p "ANIM38_middle_l_CTRL";
	rename -uid "7CD25C34-D549-FE75-3CF9-36B88EA2634A";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 6;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		66.263180542706934 96.032359849293002 9.9556759692325763
		65.742109535417327 96.591836698070495 9.1032799242316642
		64.962866392340814 97.428514409977026 9.0411599849522233
		64.38192117830539 98.052278528713046 9.8057051693303556
		64.339583720697263 98.09773649324471 10.949055277404391
		64.860654727986869 97.538259644467217 11.801451322405303
		65.639897871063383 96.701581932560686 11.863571261684744
		66.220843085098807 96.077817813824666 11.099026077306611
		66.263180542706934 96.032359849293002 9.9556759692325763
		65.742109535417327 96.591836698070495 9.1032799242316642
		64.962866392340814 97.428514409977026 9.0411599849522233
		;
createNode transform -n "ANIM38_ring_l_CTRL";
	rename -uid "6B8B8920-B743-F981-5739-34B6C4528CCF";
	addAttr -ci true -sn "bend" -ln "bend" -at "double";
	addAttr -ci true -sn "curl" -ln "curl" -at "double";
	addAttr -ci true -sn "spread" -ln "spread" -at "double";
	setAttr ".rp" -type "double3" 65.050115403998717 97.334834659197583 6.8653029113768769 ;
	setAttr ".sp" -type "double3" 65.050115403998717 97.334834659197583 6.8653029113768769 ;
	setAttr -k on ".bend";
	setAttr -k on ".curl";
	setAttr -k on ".spread";
createNode nurbsCurve -n "ANIM38_ring_l_CTRLShape" -p "ANIM38_ring_l_CTRL";
	rename -uid "450F6D4C-3B4B-5EFF-29DA-2A934EC5CB8C";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 6;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		66.011913815003552 96.302146337221728 6.3686132572909697
		65.490842807713946 96.861623185999221 5.5162172122900568
		64.711599664637433 97.698300897905753 5.4540972730106168
		64.130654450602009 98.322065016641773 6.2186424573887491
		64.088316992993882 98.367522981173437 7.3619925654627849
		64.609388000283488 97.808046132395944 8.2143886104636969
		65.388631143360001 96.971368420489412 8.2765085497431379
		65.969576357395425 96.347604301753393 7.5119633653650046
		66.011913815003552 96.302146337221728 6.3686132572909697
		65.490842807713946 96.861623185999221 5.5162172122900568
		64.711599664637433 97.698300897905753 5.4540972730106168
		;
createNode transform -n "ANIM38_pinky_l_CTRL";
	rename -uid "95A9808F-3C49-B90A-0B01-D38E8FBF659C";
	addAttr -ci true -sn "bend" -ln "bend" -at "double";
	addAttr -ci true -sn "curl" -ln "curl" -at "double";
	addAttr -ci true -sn "spread" -ln "spread" -at "double";
	setAttr ".rp" -type "double3" 63.935896644593853 98.53117755995352 3.5704369594429455 ;
	setAttr ".sp" -type "double3" 63.935896644593853 98.53117755995352 3.5704369594429455 ;
	setAttr -k on ".bend";
	setAttr -k on ".curl";
	setAttr -k on ".spread";
createNode nurbsCurve -n "ANIM38_pinky_l_CTRLShape" -p "ANIM38_pinky_l_CTRL";
	rename -uid "4AE2F113-2641-A0B9-C6C6-ADB86FC84E02";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 6;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		64.89769505559866 97.498489237977637 3.0737473053570383
		64.376624048309054 98.057966086755115 2.2213512603561263
		63.597380905232541 98.894643798661662 2.1592313210766854
		63.016435691197117 99.518407917397695 2.9237765054548177
		62.97409823358899 99.563865881929345 4.0671266135288526
		63.495169240878596 99.004389033151853 4.9195226585297664
		64.274412383955109 98.167711321245321 4.9816425978092038
		64.855357597990533 97.543947202509301 4.2170974134310732
		64.89769505559866 97.498489237977637 3.0737473053570383
		64.376624048309054 98.057966086755115 2.2213512603561263
		63.597380905232541 98.894643798661662 2.1592313210766854
		;
createNode transform -n "ANIM38_thumb_r_CTRL";
	rename -uid "12FCEC84-564C-54A5-B0F5-15994944173E";
	addAttr -ci true -sn "bend" -ln "bend" -at "double";
	addAttr -ci true -sn "curl" -ln "curl" -at "double";
	addAttr -ci true -sn "spread" -ln "spread" -at "double";
	setAttr ".rp" -type "double3" -54.584559111091231 101.03528503696113 16.863881459127569 ;
	setAttr ".sp" -type "double3" -54.584559111091231 101.03528503696113 16.863881459127569 ;
	setAttr -k on ".bend";
	setAttr -k on ".curl";
	setAttr -k on ".spread";
createNode nurbsCurve -n "ANIM38_thumb_r_CTRLShape" -p "ANIM38_thumb_r_CTRL";
	rename -uid "1E0C7DF5-BE42-0A31-3DBA-789E2B9C1A8D";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 13;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		-56.309365402905257 101.4636338781583 16.433710081891817
		-55.37492137868653 102.20083347755568 15.697557659139633
		-53.977493857298434 102.25527060805547 15.644621900301772
		-52.935676928336697 101.59505673690762 16.305911854970958
		-52.859752819277233 100.60693619576372 17.294052836363122
		-53.794196843495961 99.869736596366337 18.03020525911532
		-55.191624364884049 99.815299465866516 18.083141017953153
		-56.233441293845793 100.47551333701433 17.421851063283981
		-56.309365402905257 101.4636338781583 16.433710081891817
		-55.37492137868653 102.20083347755568 15.697557659139633
		-53.977493857298434 102.25527060805547 15.644621900301772
		;
createNode transform -n "ANIM38_index_r_CTRL";
	rename -uid "98DA5704-AD46-38CC-F45F-528C49FD5C78";
	addAttr -ci true -sn "bend" -ln "bend" -at "double";
	addAttr -ci true -sn "curl" -ln "curl" -at "double";
	addAttr -ci true -sn "spread" -ln "spread" -at "double";
	setAttr ".rp" -type "double3" -64.353689015791176 98.08259155917645 14.050570425962954 ;
	setAttr ".sp" -type "double3" -64.353689015791176 98.08259155917645 14.050570425962954 ;
	setAttr -k on ".bend";
	setAttr -k on ".curl";
	setAttr -k on ".spread";
createNode nurbsCurve -n "ANIM38_index_r_CTRLShape" -p "ANIM38_index_r_CTRL";
	rename -uid "5B8F1933-F941-CE37-0CD8-C48C1A3F1CDE";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 13;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		-65.315487426796011 97.049903237200581 13.553880771877049
		-64.794416419506391 97.60938008597806 12.701484726876137
		-64.015173276429891 98.446057797884592 12.639364787596698
		-63.43422806239446 99.069821916620626 13.403909971974832
		-63.391890604786333 99.115279881152276 14.547260080048869
		-63.912961612075947 98.555803032374797 15.399656125049781
		-64.692204755152446 97.719125320468265 15.46177606432922
		-65.27314996918787 97.095361201732231 14.697230879951086
		-65.315487426796011 97.049903237200581 13.553880771877049
		-64.794416419506391 97.60938008597806 12.701484726876137
		-64.015173276429891 98.446057797884592 12.639364787596698
		;
createNode transform -n "ANIM38_middle_r_CTRL";
	rename -uid "73C8B28A-074E-7C73-CD43-949FC36C367F";
	addAttr -ci true -sn "bend" -ln "bend" -at "double";
	addAttr -ci true -sn "curl" -ln "curl" -at "double";
	addAttr -ci true -sn "spread" -ln "spread" -at "double";
	setAttr ".rp" -type "double3" -65.301382131702098 97.065048171268856 10.452365623318483 ;
	setAttr ".sp" -type "double3" -65.301382131702098 97.065048171268856 10.452365623318483 ;
	setAttr -k on ".bend";
	setAttr -k on ".curl";
	setAttr -k on ".spread";
createNode nurbsCurve -n "ANIM38_middle_r_CTRLShape" -p "ANIM38_middle_r_CTRL";
	rename -uid "FA532915-6840-A6DD-477B-979BCDF0752D";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 13;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		-66.263180542706934 96.032359849293002 9.9556759692325763
		-65.742109535417327 96.591836698070495 9.1032799242316642
		-64.962866392340814 97.428514409977026 9.0411599849522233
		-64.38192117830539 98.052278528713046 9.8057051693303556
		-64.339583720697263 98.09773649324471 10.949055277404391
		-64.860654727986869 97.538259644467217 11.801451322405303
		-65.639897871063383 96.701581932560686 11.863571261684744
		-66.220843085098807 96.077817813824666 11.099026077306611
		-66.263180542706934 96.032359849293002 9.9556759692325763
		-65.742109535417327 96.591836698070495 9.1032799242316642
		-64.962866392340814 97.428514409977026 9.0411599849522233
		;
createNode transform -n "ANIM38_ring_r_CTRL";
	rename -uid "7EC69279-BF41-1FF9-7912-FD84E9B0BC34";
	addAttr -ci true -sn "bend" -ln "bend" -at "double";
	addAttr -ci true -sn "curl" -ln "curl" -at "double";
	addAttr -ci true -sn "spread" -ln "spread" -at "double";
	setAttr ".rp" -type "double3" -65.050115403998717 97.334834659197583 6.8653029113768769 ;
	setAttr ".sp" -type "double3" -65.050115403998717 97.334834659197583 6.8653029113768769 ;
	setAttr -k on ".bend";
	setAttr -k on ".curl";
	setAttr -k on ".spread";
createNode nurbsCurve -n "ANIM38_ring_r_CTRLShape" -p "ANIM38_ring_r_CTRL";
	rename -uid "E813FD4F-CF40-7C12-6A4A-70A799E29F16";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 13;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		-66.011913815003552 96.302146337221728 6.3686132572909697
		-65.490842807713946 96.861623185999221 5.5162172122900568
		-64.711599664637433 97.698300897905753 5.4540972730106168
		-64.130654450602009 98.322065016641773 6.2186424573887491
		-64.088316992993882 98.367522981173437 7.3619925654627849
		-64.609388000283488 97.808046132395944 8.2143886104636969
		-65.388631143360001 96.971368420489412 8.2765085497431379
		-65.969576357395425 96.347604301753393 7.5119633653650046
		-66.011913815003552 96.302146337221728 6.3686132572909697
		-65.490842807713946 96.861623185999221 5.5162172122900568
		-64.711599664637433 97.698300897905753 5.4540972730106168
		;
createNode transform -n "ANIM38_pinky_r_CTRL";
	rename -uid "92DB7055-F444-0ECE-FDB9-34B14FE11C50";
	addAttr -ci true -sn "bend" -ln "bend" -at "double";
	addAttr -ci true -sn "curl" -ln "curl" -at "double";
	addAttr -ci true -sn "spread" -ln "spread" -at "double";
	setAttr ".rp" -type "double3" -63.935896644593853 98.53117755995352 3.5704369594429455 ;
	setAttr ".sp" -type "double3" -63.935896644593853 98.53117755995352 3.5704369594429455 ;
	setAttr -k on ".bend";
	setAttr -k on ".curl";
	setAttr -k on ".spread";
createNode nurbsCurve -n "ANIM38_pinky_r_CTRLShape" -p "ANIM38_pinky_r_CTRL";
	rename -uid "985648D6-D14E-39EF-F452-0084D90F2A3F";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 13;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		-64.89769505559866 97.498489237977637 3.0737473053570383
		-64.376624048309054 98.057966086755115 2.2213512603561263
		-63.597380905232541 98.894643798661662 2.1592313210766854
		-63.016435691197117 99.518407917397695 2.9237765054548177
		-62.97409823358899 99.563865881929345 4.0671266135288526
		-63.495169240878596 99.004389033151853 4.9195226585297664
		-64.274412383955109 98.167711321245321 4.9816425978092038
		-64.855357597990533 97.543947202509301 4.2170974134310732
		-64.89769505559866 97.498489237977637 3.0737473053570383
		-64.376624048309054 98.057966086755115 2.2213512603561263
		-63.597380905232541 98.894643798661662 2.1592313210766854
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
// End of ANIM38_assign09_controlCurves.ma
