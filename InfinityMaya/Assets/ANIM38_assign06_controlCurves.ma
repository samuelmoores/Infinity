//Maya ASCII 2023 scene
//Name: ANIM38_assign06_controlCurves.ma
//Last modified: Thu, Sep 29, 2022 06:49:22 PM
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
fileInfo "UUID" "572D856F-FA4B-3B53-D024-228766A6537C";
createNode transform -n "leg_l_CTRL";
	rename -uid "669B1B41-954F-8909-FF65-04B520EBE642";
	setAttr ".ovc" 13;
	setAttr ".rp" -type "double3" 18.986684799194336 0 -8.2723655700683594 ;
	setAttr ".sp" -type "double3" 18.986684799194336 0 -8.2723655700683594 ;
createNode nurbsCurve -n "leg_l_CTRLShape" -p "leg_l_CTRL";
	rename -uid "C896620B-1E40-2B05-C110-E29E5ACE1E40";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 6;
	setAttr ".ovrgb" -type "float3" 0.068222277 0.64300001 0 ;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		24.105954543407961 0 -17.425261756094834
		16.825221452316125 0 -17.99904615427841
		10.742293520681324 0 -14.651631643279064
		14.779689261976607 0 -0.6481946543018533
		12.704674933205874 0 16.433421057995879
		26.492691823746114 0 18.391983518856655
		33.400838951356945 0 9.8097690102445227
		28.290317023470237 0 -8.7414326192533895
		24.105954543407961 0 -17.425261756094834
		16.825221452316125 0 -17.99904615427841
		10.742293520681324 0 -14.651631643279064
		;
createNode transform -n "legTwist_l_CTRL";
	rename -uid "48CAB072-F642-DE11-9AF7-E7B1F373C001";
	setAttr ".ovc" 17;
	setAttr ".rp" -type "double3" 13.816908836364746 55.111946105957031 51.213645728399513 ;
	setAttr ".sp" -type "double3" 13.816908836364746 55.111946105957031 51.213645728399513 ;
createNode nurbsCurve -n "man_lfArmPvcCRVShape" -p "legTwist_l_CTRL";
	rename -uid "C9E94CD8-7141-D1C5-79E1-A9AAB827775F";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 6;
	setAttr ".cc" -type "nurbsCurve" 
		1 13 0 no 3
		14 0 1 2 3 4 5 6 7 8 9 10 11 12 13
		14
		13.753326435875124 55.564358393277445 49.010516045282913
		14.123525226181251 52.930257129469908 50.756787326517099
		16.045011991033284 55.425085583117152 51.213645728399513
		13.510292446548249 57.293635082444098 51.670504130281898
		11.588805681696215 54.798806628796854 51.213645728399484
		13.753326435875124 55.564358393277445 49.010516045282913
		16.045011991033284 55.425085583117152 51.213645728399513
		13.880491236854382 54.659533818636589 53.416775411516113
		11.588805681696215 54.798806628796854 51.213645728399484
		14.123525226181251 52.930257129469908 50.756787326517099
		13.753326435875124 55.564358393277445 49.010516045282913
		13.510292446548249 57.293635082444098 51.670504130281898
		13.880491236854382 54.659533818636589 53.416775411516113
		14.123525226181251 52.930257129469908 50.756787326517099
		;
createNode transform -n "leg_r_CTRL";
	rename -uid "CACF387A-7A4C-34B3-639B-9E88351089A1";
	setAttr ".ovc" 13;
	setAttr ".rp" -type "double3" -18.986700057983398 -0.00093955473530726863 -8.2723703384399414 ;
	setAttr ".sp" -type "double3" -18.986700057983398 -0.00093955473530726863 -8.2723703384399414 ;
createNode nurbsCurve -n "leg_r_CTRLShape" -p "leg_r_CTRL";
	rename -uid "4BAC29C3-574F-B0EF-E66C-00B599581E02";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 13;
	setAttr ".ovrgb" -type "float3" 0.068222277 0.64300001 0 ;
	setAttr ".cc" -type "nurbsCurve" 
		3 8 2 no 3
		13 -2 -1 0 1 2 3 4 5 6 7 8 9 10
		11
		-24.105954181011715 2.2314424963547652e-05 -17.425261642846003
		-16.825221089919875 2.2314424963547652e-05 -17.99904604102958
		-10.742293158285079 2.2314424963547652e-05 -14.651631530030238
		-14.779688899580364 2.2314424963547652e-05 -0.64819454105302743
		-12.704674570809637 2.2314424963547652e-05 16.433421171244717
		-26.492691461349875 2.2314424963547652e-05 18.391983632105479
		-33.40083858896071 2.2314424963547652e-05 9.8097691234933464
		-28.290316661073991 2.2314424963547652e-05 -8.7414325060045659
		-24.105954181011715 2.2314424963547652e-05 -17.425261642846003
		-16.825221089919875 2.2314424963547652e-05 -17.99904604102958
		-10.742293158285079 2.2314424963547652e-05 -14.651631530030238
		;
createNode transform -n "legTwist_r_CTRL";
	rename -uid "AE7BBFA7-0C4D-E501-9C87-27AEC7041936";
	setAttr ".ovc" 17;
	setAttr ".rp" -type "double3" -13.816900253295898 55.111900329589844 51.213645728399456 ;
	setAttr ".sp" -type "double3" -13.816900253295898 55.111900329589844 51.213645728399456 ;
createNode nurbsCurve -n "man_lfArmPvcCRVShape" -p "legTwist_r_CTRL";
	rename -uid "D8AE74CB-CC43-15B2-B651-EC9BC9E785D4";
	setAttr -k off ".v";
	setAttr ".ove" yes;
	setAttr ".ovc" 13;
	setAttr ".cc" -type "nurbsCurve" 
		1 13 0 no 3
		14 0 1 2 3 4 5 6 7 8 9 10 11 12 13
		14
		-13.753317852806276 55.564312616910257 49.010516045282856
		-14.123516643112403 52.93021135310272 50.756787326517042
		-16.045003407964437 55.425039806749965 51.213645728399456
		-13.510283863479401 57.29358930607691 51.670504130281842
		-11.588797098627367 54.798760852429666 51.213645728399428
		-13.753317852806276 55.564312616910257 49.010516045282856
		-16.045003407964437 55.425039806749965 51.213645728399456
		-13.880482653785535 54.659488042269402 53.416775411516056
		-11.588797098627367 54.798760852429666 51.213645728399428
		-14.123516643112403 52.93021135310272 50.756787326517042
		-13.753317852806276 55.564312616910257 49.010516045282856
		-13.510283863479401 57.29358930607691 51.670504130281842
		-13.880482653785535 54.659488042269402 53.416775411516056
		-14.123516643112403 52.93021135310272 50.756787326517042
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
	setAttr -av ".msaa";
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
	setAttr ".cfp" -type "string" "<MAYA_RESOURCES>/OCIO-configs/Maya2022-default/config.ocio";
	setAttr ".vtn" -type "string" "ACES 1.0 SDR-video (sRGB)";
	setAttr ".vn" -type "string" "ACES 1.0 SDR-video";
	setAttr ".dn" -type "string" "sRGB";
	setAttr ".wsn" -type "string" "ACEScg";
	setAttr ".otn" -type "string" "ACES 1.0 SDR-video (sRGB)";
	setAttr ".potn" -type "string" "ACES 1.0 SDR-video (sRGB)";
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
// End of ANIM38_assign06_controlCurves.ma
