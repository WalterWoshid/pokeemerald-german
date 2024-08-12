SlateportCity_SternsShipyard_2F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_2F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_2F_Text_ShipDesignMoreLikeBuilding:
	.ifdef ENGLISH
	.string "Designing a large ship is more like\n"
	.string "making a big building than putting\l"
	.string "together a transportation vehicle.$"
	.else
	.ifdef GERMAN
	.string "Die Konstruktion eines großen Schiffes\n"
	.string "ist eher vergleichbar mit der eines\l"
	.string "Gebäudes, als eines Transportmittels.$"
	.endif
	.endif

SlateportCity_SternsShipyard_2F_Text_FloatsBecauseBuoyancy:
	.ifdef ENGLISH
	.string "Don't you think it's strange that\n"
	.string "a ship made of heavy iron floats?\p"
	.string "It floats because of a principle\n"
	.string "called buoyancy.$"
	.else
	.ifdef GERMAN
	.string "Findest du es nicht auch seltsam, dass\n"
	.string "ein Schiff aus Eisen gebaut wird?\p"
	.string "Es schwimmt aufgrund des so genannten\n"
	.string "Auftriebs.$"
	.endif
	.endif

