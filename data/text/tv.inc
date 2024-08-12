LilycoveCity_ContestLobby_Text_InterviewRequest:
	.ifdef ENGLISH
	.string "Oh, hello! You were in a POKéMON\n"
	.string "CONTEST, weren't you?\l"
	.string "It's easy to tell from your POKéMON.\p"
	.string "I'm a reporter. I'm working on a story\n"
	.string "on POKéMON CONTESTS.\p"
	.string "If I may, would you be willing to answer\n"
	.string "a few questions?$"
	.else
	.ifdef GERMAN
	.string "Du hast an einem POKéMON WETTBEWERB\n"
	.string "teilgenommen, stimmt’s?\p"
	.string "Da kannst du mir doch etwas über\n"
	.string "dein POKéMON erzählen.\p"
	.string "Ich bin Reporter. Ich arbeite an einer\n"
	.string "Geschichte über POKéMON WETTBEWERBe.\p"
	.string "Würdest du mir wohl einige Fragen\n"
	.string "beantworten?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_DescribeContest:
	.ifdef ENGLISH
	.string "Oh, you will?\n"
	.string "Thank you.\p"
	.string "Briefly, how would you describe the\n"
	.string "CONTEST you just entered?$"
	.else
	.ifdef GERMAN
	.string "Oh, das machst du?\n"
	.string "Herzlichen Dank.\p"
	.string "Beschreibe mir doch kurz den WETTBE-\n"
	.string "WERB, an dem du gerade teilgenommen\l"
	.string "hast.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_WhatImageWhenYouHearX:
	.ifdef ENGLISH
	.string "Ah, I see.\n"
	.string "That's a very edifying comment.\p"
	.string "You get a good feel for what\n"
	.string "the CONTEST was like.\p"
	.string "I've got one last question.\p"
	.string "When you hear the word “{STR_VAR_2},”\n"
	.string "what image do you get?$"
	.else
	.ifdef GERMAN
	.string "Ah, ich verstehe.\n"
	.string "Das ist ein bewegender Kommentar.\p"
	.string "Man bekommt ein gutes Bild davon,\n"
	.string "wie dieser WETTBEWERB war.\p"
	.string "Ich habe eine letzte Frage.\p"
	.string "Wenn du das Wort “{STR_VAR_2}” hörst,\n"
	.string "was für ein Bild hast du dann vor Augen?$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_ThatsAllForInterview:
	.ifdef ENGLISH
	.string "I see!\p"
	.string "So that's how you imagine the concept\n"
	.string "of “{STR_VAR_2}” to be.\p"
	.string "Thank you!\n"
	.string "You've given me some good ideas.\p"
	.string "I think I can write a good story on\n"
	.string "POKéMON CONTESTS now.\p"
	.string "Maybe, just maybe, this story will even\n"
	.string "make it to television.\l"
	.string "I hope you'll look forward to it!$"
	.else
	.ifdef GERMAN
	.string "Oh, hm.\p"
	.string "Das stellst du dir also unter dem\n"
	.string "Begriff “{STR_VAR_2}” vor.\p"
	.string "Danke schön!\n"
	.string "Du hast mir einige gute Ideen geliefert.\p"
	.string "Jetzt kann ich eine gute Geschichte\n"
	.string "über die POKéMON WETTBEWERBe\l"
	.string "schreiben.\p"
	.string "Vielleicht, aber nur vielleicht, findet\n"
	.string "sie auch ihren Weg ins Fernsehen.\l"
	.string "Ich hoffe, du schaltest dann ein!$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_PleaseDoShareStoryWithMe:
	.ifdef ENGLISH
	.string "Oh, too bad…\p"
	.string "Well, if you come across a good story,\n"
	.string "please do share it with me.$"
	.else
	.ifdef GERMAN
	.string "Oh, das ist wirklich schade…\p"
	.string "Nun, wenn du eine gute Geschichte auf\n"
	.string "Lager hast, melde dich wieder bei mir.$"
	.endif
	.endif

LilycoveCity_ContestLobby_Text_LookingForwardToNextContest:
	.ifdef ENGLISH
	.string "I'll be looking forward to your next\n"
	.string "POKéMON CONTEST.$"
	.else
	.ifdef GERMAN
	.string "Ich freue mich schon auf deinen\n"
	.string "nächsten POKéMON WETTBEWERB.$"
	.endif
	.endif

gTVBravoTrainerText00::
	.ifdef ENGLISH
	.string "Yeah!\n"
	.string "It's BRAVO TRAINER time!\p"
	.string "Today, we're going to profile a POKéMON\n"
	.string "belonging to {STR_VAR_1}.\p"
	.string "Now, this POKéMON boasts a {STR_VAR_3}\n"
	.string "Rank in the {STR_VAR_2} Category.$"
	.else
	.ifdef GERMAN
	.string "Yeah!\n"
	.string "Es ist BRAVO TRAINER Zeit!\p"
	.string "Heute stellen wir ein POKéMON vor,\n"
	.string "das zu {STR_VAR_1} gehört.\p"
	.string "Dieses POKéMON hat eine {STR_VAR_2}-\n"
	.string "Wertung in der {STR_VAR_3}-Klasse\l"
	.string "bekommen.$"
	.endif
	.endif

gTVBravoTrainerText01::
	.ifdef ENGLISH
	.string "Introducing {STR_VAR_2} the\n"
	.string "{STR_VAR_1}!\p"
	.string "The nickname {STR_VAR_2}…\p"
	.string "Even the nickname exudes an air that\n"
	.string "proclaims “{STR_VAR_3}”!$"
	.else
	.ifdef GERMAN
	.string "Begrüßt {STR_VAR_2},\n"
	.string "das {STR_VAR_1}!\p"
	.string "Der Kosename {STR_VAR_2}…\p"
	.string "Selbst dieser Kosename strahlt die\n"
	.string "Aura von “{STR_VAR_3}” aus!$"
	.endif
	.endif

gTVBravoTrainerText02::
	.ifdef ENGLISH
	.string "Anyway, when the TRAINER {STR_VAR_1}\n"
	.string "entered the POKéMON in a CONTEST,\l"
	.string "we managed to get a few impassioned\l"
	.string "quotes about the trusty partner.$"
	.else
	.ifdef GERMAN
	.string "Als der TRAINER {STR_VAR_1} sein POKéMON\n"
	.string "in einem WETTBEWERB antreten ließ,\l"
	.string "haben wir es geschafft, einige leiden-\l"
	.string "schaftliche Aussagen zu erhalten.$"
	.endif
	.endif

gTVBravoTrainerText03::
	.ifdef ENGLISH
	.string "Asked about the CONTEST afterwards,\n"
	.string "{STR_VAR_1} happily replied with a huge\l"
	.string "grin, “{STR_VAR_2}!”\p"
	.string "Well, sure, {STR_VAR_1}'s POKéMON came in\n"
	.string "number {STR_VAR_3} in the CONTEST.\p"
	.string "That line perfectly suits {STR_VAR_1}\n"
	.string "right now, I'd say!$"
	.else
	.ifdef GERMAN
	.string "Als {STR_VAR_1} nach dem WETTBEWERB über\n"
	.string "diesen befragt wurde, bekamen wir ein\l"
	.string "breites Grinsen und folgende Antwort:\l"
	.string "“{STR_VAR_2}!”\p"
	.string "Nun, sicher, das POKéMON von {STR_VAR_1}\n"
	.string "kam auf Platz {STR_VAR_3} im WETTBEWERB.\p"
	.string "Die Aussage passt absolut zu {STR_VAR_1},\n"
	.string "das ist meine Meinung!$"
	.endif
	.endif

gTVBravoTrainerText04::
	.ifdef ENGLISH
	.string "Asked about the CONTEST afterwards,\n"
	.string "{STR_VAR_1} replied with a tinge of\l"
	.string "bitterness, “{STR_VAR_2}.”\p"
	.string "Well, sure, {STR_VAR_1}'s POKéMON came in\n"
	.string "number {STR_VAR_3} in the CONTEST.\p"
	.string "{STR_VAR_1}'s disappointment comes across\n"
	.string "loud and clear, I'd say!$"
	.else
	.ifdef GERMAN
	.string "Als {STR_VAR_1} nach dem WETTBEWERB über\n"
	.string "diesen befragt wurde, bekamen wir die\l"
	.string "bittere Antwort: “{STR_VAR_2}!”\p"
	.string "Nun, sicher, das POKéMON von {STR_VAR_1}\n"
	.string "kam auf Platz {STR_VAR_3} im WETTBEWERB.\p"
	.string "Die Enttäuschung von {STR_VAR_1} wird hier\n"
	.string "mehr als deutlich, das ist meine\l"
	.string "Meinung.$"
	.endif
	.endif

gTVBravoTrainerText05::
	.ifdef ENGLISH
	.string "Wouldn't you also like to know what\n"
	.string "{STR_VAR_1} imagines {STR_VAR_2} to be?\p"
	.string "You bet we did!\n"
	.string "So we asked, of course!\p"
	.string "The answer is all perfectly condensed:\n"
	.string "“{STR_VAR_3}!”\p"
	.string "That's what the concept of {STR_VAR_2}\n"
	.string "represents to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Möchtet ihr auch wissen, was {STR_VAR_1}\n"
	.string "sich unter {STR_VAR_2} vorstellt?\p"
	.string "Ihr könnt darauf wetten, dass wir\n"
	.string "danach gefragt haben! Natürlich!\p"
	.string "Die Antwort war klipp und klar:\n"
	.string "“{STR_VAR_3}!”\p"
	.string "Das ist es, was {STR_VAR_2} für {STR_VAR_1}\n"
	.string "repräsentiert!$"
	.endif
	.endif

gTVBravoTrainerText06::
	.ifdef ENGLISH
	.string "The last move {STR_VAR_2} used by\n"
	.string "the {STR_VAR_1} is entirely about\l"
	.string "“{STR_VAR_3}”!$"
	.else
	.ifdef GERMAN
	.string "Die letzte Attacke, {STR_VAR_2}, die\n"
	.string "von {STR_VAR_1} eingesetzt wurde,\l"
	.string "ist ganz klar “{STR_VAR_3}!”$"
	.endif
	.endif

gTVBravoTrainerText07::
	.ifdef ENGLISH
	.string "Bravo, {STR_VAR_1}!\n"
	.string "Bravo, {STR_VAR_2}!\p"
	.string "I hope we can count on seeing\n"
	.string "{STR_VAR_1} scale even greater heights!\p"
	.string "That's all the time we have!\n"
	.string "Until next time, see you!$"
	.else
	.ifdef GERMAN
	.string "Bravo, {STR_VAR_1}!\n"
	.string "Bravo, {STR_VAR_2}!\p"
	.string "Wir hoffen, dass {STR_VAR_1} noch höhere\n"
	.string "Gipfel erklimmen wird!\p"
	.string "Unsere Zeit ist mal wieder abgelaufen!\n"
	.string "Bis zum nächsten Mal! Tschüss!$"
	.endif
	.endif

gTVBravoTrainerText08::
	.ifdef ENGLISH
	.string "Introducing the TRAINER's {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Wir stellen vor: TRAINERs {STR_VAR_1}!$"
	.endif
	.endif

BattleFrontier_BattleTowerLobby_Text_InterviewRequest::
	.ifdef ENGLISH
	.string "Hello! You're the TRAINER who just had\n"
	.string "a battle, right?\p"
	.string "I'm gathering interviews with TRAINERS\n"
	.string "all over the place.\p"
	.string "May I get a few words from you about\n"
	.string "your impressions on battling?$"
	.else
	.ifdef GERMAN
	.string "Hallo! Du bist der TRAINER, der gerade\n"
	.string "gekämpft hat, richtig?\p"
	.string "Ich interviewe TRAINER in der ganzen\n"
	.string "Welt.\p"
	.string "Würdest du mir deine Eindrücke über\n"
	.string "das Kämpfen schildern?$"
	.endif
	.endif

BattleFrontier_BattleTowerLobby_Text_HowDidBattleTowerTurnOut::
	.ifdef ENGLISH
	.string "You will? Really?\n"
	.string "Thank you!\l"
	.string "Then, uh…\p"
	.string "How did things turn out in\n"
	.string "the BATTLE TOWER today?\p"
	.string "Were you satisfied with the battle?\n"
	.string "Or are you unhappy?$"
	.else
	.ifdef GERMAN
	.string "Ja? Wirklich?\n"
	.string "Danke schön!\l"
	.string "Dann, äh…\p"
	.string "Wie war es heute im DUELLTURM?\p"
	.string "Warst du mit dem Kampf zufrieden?\n"
	.string "Oder bist du unzufrieden?$"
	.endif
	.endif

BattleFrontier_BattleTowerLobby_Text_SorryWeDisturbedYou::
	.ifdef ENGLISH
	.string "Oh…\n"
	.string "Sorry we disturbed you.\p"
	.string "Please give us an interview the next\n"
	.string "time you visit the BATTLE TOWER.$"
	.else
	.ifdef GERMAN
	.string "Oh…\n"
	.string "Tut mir Leid, dich zu stören.\p"
	.string "Bitte gib uns ein Interview, wenn du\n"
	.string "wieder im DUELLTURM kämpfst.$"
	.endif
	.endif

BattleFrontier_BattleTowerLobby_Text_ObviousYouHadGreatBattle::
	.ifdef ENGLISH
	.string "Well, of course!\p"
	.string "That unmistakable look of satisfaction\n"
	.string "on your face…\p"
	.string "It's obvious that you've had a great\n"
	.string "battle.$"
	.else
	.ifdef GERMAN
	.string "Ja, natürlich!\p"
	.string "Da ist dieser untrügliche Ausdruck der\n"
	.string "Zufriedenheit auf deinem Gesicht…\p"
	.string "Ganz offensichtlich hattest du einen\n"
	.string "großartigen Kampf!$"
	.endif
	.endif

BattleFrontier_BattleTowerLobby_Text_DifficultToMakeBattleTurnOutAsPlanned::
	.ifdef ENGLISH
	.string "Oh, I see…\p"
	.string "Well, it certainly is difficult to make a\n"
	.string "battle turn out exactly as planned.$"
	.else
	.ifdef GERMAN
	.string "Oh, ich verstehe…\p"
	.string "Nun, es ist immer schwer, den Kampf so\n"
	.string "zu beeinflussen, wie man es möchte.$"
	.endif
	.endif

BattleFrontier_BattleTowerLobby_Text_DescribeYourBattle::
	.ifdef ENGLISH
	.string "Oh, oh, may I ask one more question?\p"
	.string "If you were to describe your\n"
	.string "impressions about this battle with\l"
	.string "one saying, what would it be?$"
	.else
	.ifdef GERMAN
	.string "Darf ich dir noch eine Frage stellen?\p"
	.string "Wenn du deine Eindrücke über diesen\n"
	.string "Kampf beschreiben müsstest, was\l"
	.string "würdest du dann sagen?$"
	.endif
	.endif

BattleFrontier_BattleTowerLobby_Text_ThatsGreatLine::
	.ifdef ENGLISH
	.string "Oh, that is stunningly cool!\p"
	.string "That's a great line!\n"
	.string "I hope you'll do great next time, too.\p"
	.string "I hope to see you again!$"
	.else
	.ifdef GERMAN
	.string "Das ist erstaunlich cool!\p"
	.string "Eine großartige Sache! Ich wünsche dir\n"
	.string "im nächsten Kampf genauso viel Glück!\p"
	.string "Ich hoffe, wir treffen uns bald wieder!$"
	.endif
	.endif

BattleFrontier_BattleTowerLobby_Text_SilentType::
	.ifdef ENGLISH
	.string "Oh, I see…\p"
	.string "Still, being the silent type is also\n"
	.string "cool, isn't it?\p"
	.string "I hope you'll give me the opportunity\n"
	.string "to share your thoughts again!$"
	.else
	.ifdef GERMAN
	.string "Oh, ich verstehe…\p"
	.string "Nun, auch die ruhigen Typen sind cool,\n"
	.string "nicht wahr?\p"
	.string "Ich hoffe, du gibst mir bald wieder die\n"
	.string "Möglichkeit, deine Eindrücke\l"
	.string "festzuhalten!$"
	.endif
	.endif

BattleFrontier_BattleTowerLobby_Text_LookingForwardToNextBattle::
	.ifdef ENGLISH
	.string "I'll be looking forward to your\n"
	.string "next battle!$"
	.else
	.ifdef GERMAN
	.string "Ich freue mich schon auf deinen\n"
	.string "nächsten Kampf!$"
	.endif
	.endif

BravoTrainerBattleTower_Text_Intro::
	.ifdef ENGLISH
	.string "Yeah!\n"
	.string "It's BRAVO TRAINER time!\p"
	.string "Today, we're going to profile {STR_VAR_1},\n"
	.string "who took the BATTLE TOWER challenge!\p"
	.string "For the challenge, {STR_VAR_1} entered\n"
	.string "one wicked {STR_VAR_2}.$"
	.else
	.ifdef GERMAN
	.string "Yeah!\n"
	.string "Es ist BRAVO TRAINER Zeit!\p"
	.string "Heute stellen wir {STR_VAR_1} vor. {STR_VAR_1}\n"
	.string "hat sich der Herausforderung im\l"
	.string "DUELLTURM gestellt!\p"
	.string "Bei dieser Begegnung hatte {STR_VAR_1}\n"
	.string "das listige {STR_VAR_2} mitgebracht.$"
	.endif
	.endif

BravoTrainerBattleTower_Text_NewRecord::
	.ifdef ENGLISH
	.string "The pair set a new record of {STR_VAR_2} wins\n"
	.string "in a row in {STR_VAR_1} competition!\l"
	.string "Bravo, TRAINER!$"
	.else
	.ifdef GERMAN
	.string "Das Paar stellte einen neuen Rekord von\n"
	.string "{STR_VAR_2} Siegen in Folge in einer\l"
	.string "{STR_VAR_1}-Konkurrenz auf!\l"
	.string "Bravo, TRAINER!$"
	.endif
	.endif

BravoTrainerBattleTower_Text_Lost::
	.ifdef ENGLISH
	.string "The twosome finally succumbed to\n"
	.string "{STR_VAR_1} in match number {STR_VAR_2}.\l"
	.string "Nice try, TRAINER!\p"
	.string "But, hey, it's just bad luck to run into\n"
	.string "{STR_VAR_1} so early in the challenge.\p"
	.string "We asked the TRAINER for impressions\n"
	.string "on the match with {STR_VAR_1}.$"
	.else
	.ifdef GERMAN
	.string "Die beiden scheiterten schließlich an\n"
	.string "{STR_VAR_1} im Kampf Nummer {STR_VAR_2}.\l"
	.string "Netter Versuch, TRAINER!\p"
	.string "Es war einfach nur großes Pech, so\n"
	.string "früh während dieser Herausforderung\l"
	.string "auf {STR_VAR_1} zu treffen.\p"
	.string "Wir fragten den TRAINER nach den\n"
	.string "Eindrücken, die der Kampf gegen\l"
	.string "{STR_VAR_1} hinterlassen hat.$"
	.endif
	.endif

BravoTrainerBattleTower_Text_Won::
	.ifdef ENGLISH
	.string "The twosome won it all by defeating\n"
	.string "{STR_VAR_1}'s {STR_VAR_2} thoroughly.\l"
	.string "Bravo, TRAINER!\p"
	.string "Knocking off even {STR_VAR_1}…\n"
	.string "It defies belief! Simply astounding!\p"
	.string "We asked the TRAINER for impressions\n"
	.string "on the moment of glory.$"
	.else
	.ifdef GERMAN
	.string "Die beiden haben gewonnen, indem sie\n"
	.string "{STR_VAR_2} von {STR_VAR_1} klar\l"
	.string "besiegt haben. Bravo, TRAINER!\p"
	.string "Sogar {STR_VAR_1} wurde besiegt…\n"
	.string "Das ist unglaublich! Einfach\l"
	.string "unglaublich!\p"
	.string "Wir haben den TRAINER nach den\n"
	.string "Eindrücken im Moment des Sieges\l"
	.string "gefragt.$"
	.endif
	.endif

BravoTrainerBattleTower_Text_LostFinal::
	.ifdef ENGLISH
	.string "After a string of wins, the pair finally\n"
	.string "succumbed to {STR_VAR_1}'s {STR_VAR_2},\l"
	.string "their final hurdle.\p"
	.string "Nice try, TRAINER!\p"
	.string "Still, you have to give credit.\n"
	.string "You don't see many famous combinations\l"
	.string "like {STR_VAR_1} and {STR_VAR_2}.\p"
	.string "We asked the TRAINER for impressions\n"
	.string "on battling the celebrity pair.$"
	.else
	.ifdef GERMAN
	.string "Nach einer Reihe von Siegen musste sich\n"
	.string "das Paar schließlich doch {STR_VAR_2}\l"
	.string "von {STR_VAR_1} geschlagen geben.\p"
	.string "Netter Versuch, TRAINER!\p"
	.string "Man sieht nicht oft so ein wunderbares\n"
	.string "Team wie {STR_VAR_1} und\l"
	.string "{STR_VAR_2}. Das könnt ihr glauben!\p"
	.string "Wir haben den TRAINER gefragt, wie es\n"
	.string "war, gegen dieses Super-Paar zu\l"
	.string "kämpfen.$"
	.endif
	.endif

BravoTrainerBattleTower_Text_Satisfied::
	.ifdef ENGLISH
	.string "This is what the TRAINER had to say:\n"
	.string "“I'm satisfied!”\p"
	.string "Now isn't that a refreshing reply?\n"
	.string "Bravo, TRAINER!\p"
	.string "Isn't it out-and-out awesome to be\n"
	.string "able to battle to full satisfaction?\p"
	.string "I found out exactly how satisfied\n"
	.string "when I heard the TRAINER say this:$"
	.else
	.ifdef GERMAN
	.string "Und das hat uns der TRAINER gesagt:\n"
	.string "“Ich bin zufrieden!”\p"
	.string "Ist das nicht eine erfrischend offene\n"
	.string "Antwort? Bravo, TRAINER!\p"
	.string "Aber ist ein so eingefleischter TRAINER\n"
	.string "überhaupt in der Lage, mit einem Kampf\l"
	.string "zufrieden zu sein?\p"
	.string "Ich habe herausgefunden, wie zufrieden\n"
	.string "der TRAINER war, als ich diese Worte\l"
	.string "hörte:$"
	.endif
	.endif

BravoTrainerBattleTower_Text_Unsatisfied::
	.ifdef ENGLISH
	.string "This is what the TRAINER had to say:\n"
	.string "“I'm not satisfied…”\p"
	.string "Our TRAINER was obviously a little down\n"
	.string "when that was uttered.\p"
	.string "Still, it's not easy to be able to battle\n"
	.string "with complete satisfaction, am I right?\p"
	.string "Anyway, I found out how dissatisfied\n"
	.string "our TRAINER was when I heard this:$"
	.else
	.ifdef GERMAN
	.string "Und das hat uns der TRAINER verraten:\n"
	.string "“Ich bin nicht zufrieden…”\p"
	.string "Unser TRAINER war wohl gerade etwas\n"
	.string "niedergeschlagen, als er das sagte.\p"
	.string "Und es ist nicht immer leicht, nach\n"
	.string "einem Kampf voll zufrieden zu sein,\l"
	.string "richtig?\p"
	.string "Nun, wir haben nachgehakt und heraus-\n"
	.string "gefunden, wie unzufrieden der TRAINER\l"
	.string "tatsächlich war:$"
	.endif
	.endif

BravoTrainerBattleTower_Text_None1::
	.ifdef ENGLISH
	.string "None$"
	.else
	.ifdef GERMAN
	.string "Nichts$"
	.endif
	.endif

BravoTrainerBattleTower_Text_None2::
	.ifdef ENGLISH
	.string "None$"
	.else
	.ifdef GERMAN
	.string "Nichts$"
	.endif
	.endif

BravoTrainerBattleTower_Text_None3::
	.ifdef ENGLISH
	.string "None$"
	.else
	.ifdef GERMAN
	.string "Nichts$"
	.endif
	.endif

BravoTrainerBattleTower_Text_None4::
	.ifdef ENGLISH
	.string "None$"
	.else
	.ifdef GERMAN
	.string "Nichts$"
	.endif
	.endif

BravoTrainerBattleTower_Text_Response::
	.ifdef ENGLISH
	.string "“{STR_VAR_1}.”$"
	.else
	.ifdef GERMAN
	.string "“{STR_VAR_1}”.$"
	.endif
	.endif

BravoTrainerBattleTower_Text_ResponseSatisfied::
	.ifdef ENGLISH
	.string "“{STR_VAR_1}.”\n"
	.string "Now isn't that great?\p"
	.string "It really expresses {STR_VAR_2}'s joy,\n"
	.string "I'd say.\p"
	.string "That battle with {STR_VAR_3} at the\n"
	.string "end… It really was what you'd call\l"
	.string "“{STR_VAR_1}”!$"
	.else
	.ifdef GERMAN
	.string "“{STR_VAR_1}”.\n"
	.string "Ist das nicht großartig?\p"
	.string "Das drückt wahrhaftig die Freude von\n"
	.string "{STR_VAR_2} aus. Das würde ich doch sagen!\p"
	.string "Am Ende noch der Kampf gegen\n"
	.string "{STR_VAR_3}… Das war wirklich das, was\l"
	.string "man “{STR_VAR_1}” nennt!$"
	.endif
	.endif

BravoTrainerBattleTower_Text_ResponseUnsatisfied::
	.ifdef ENGLISH
	.string "“{STR_VAR_1}.”\n"
	.string "Now isn't that fitting?\p"
	.string "That battle with {STR_VAR_3} at the\n"
	.string "end… You can't describe it as anything\l"
	.string "else but “{STR_VAR_1}”!\p"
	.string "{STR_VAR_2}'s disappointment comes across\n"
	.string "loud and clear, I'd say!$"
	.else
	.ifdef GERMAN
	.string "“{STR_VAR_1}”.\n"
	.string "Eine treffende Aussage!\p"
	.string "Das Ende des Kampfes gegen\n"
	.string "{STR_VAR_3}… Man kann es nur\l"
	.string "“{STR_VAR_1}” nennen!\p"
	.string "Ich finde, die Enttäuschung von\n"
	.string "{STR_VAR_2} wird mehr als deutlich.$"
	.endif
	.endif

BravoTrainerBattleTower_Text_Outro::
	.ifdef ENGLISH
	.string "Bravo, {STR_VAR_1}!\n"
	.string "Bravo, {STR_VAR_2}!\p"
	.string "I hope we can count on seeing\n"
	.string "{STR_VAR_1} scale even greater heights!\p"
	.string "That's all the time we have!\n"
	.string "Until next time, see you!$"
	.else
	.ifdef GERMAN
	.string "Bravo, {STR_VAR_1}!\n"
	.string "Bravo, {STR_VAR_2}!\p"
	.string "Ich hoffe, wir sehen {STR_VAR_1} noch\n"
	.string "höhere Gipfel erklimmen!\p"
	.string "Das war’s für den Moment!\n"
	.string "Bis zur nächsten Sendung!$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_InterviewRequestHasName:
	.ifdef ENGLISH
	.string "Wow!\p"
	.string "It's plain to see that you lavish your\n"
	.string "love on your {STR_VAR_1}.\p"
	.string "Okay, it's named {STR_VAR_2}.\p"
	.string "Can I ask you a favor?\p"
	.string "I'm a TV reporter, and I'm running\n"
	.string "a survey on POKéMON.\p"
	.string "Would you be willing to answer a few\n"
	.string "simple questions for me?$"
	.else
	.ifdef GERMAN
	.string "Wow!\p"
	.string "Es ist ganz offensichtlich, dass du\n"
	.string "deine Liebe {STR_VAR_1} schenkst.\p"
	.string "Okay, es heißt {STR_VAR_2}.\p"
	.string "Darf ich dich um einen Gefallen bitten?\p"
	.string "Ich bin TV-Reporter und mache eine\n"
	.string "Umfrage zum Thema POKéMON.\p"
	.string "Würdest du mir bitte ein paar einfache\n"
	.string "Fragen beantworten?$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_HereGoesQuickAnswers:
	.ifdef ENGLISH
	.string "Great! Thank you!\p"
	.string "Okay, here goes.\n"
	.string "I just need quick answers, okay?$"
	.else
	.ifdef GERMAN
	.string "Großartig! Danke schön!\p"
	.string "Okay, los geht’s. Ich brauche\n"
	.string "kurze, knappe Antworten, okay?$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_DescribeFeelingsFirstMetMon:
	.ifdef ENGLISH
	.string "When you first met {STR_VAR_1},\n"
	.string "what did you feel?\p"
	.string "How would you describe your feelings\n"
	.string "at the time?$"
	.else
	.ifdef GERMAN
	.string "Als du {STR_VAR_1} zum ersten Mal ge-\n"
	.string "sehen hast, was war das für\l"
	.string "ein Gefühl?\p"
	.string "Wie würdest du die Gefühle zu dem\n"
	.string "Zeitpunkt beschreiben?$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_LikenMonToSomethingYouLike:
	.ifdef ENGLISH
	.string "Your {STR_VAR_1} is cared for lovingly.\p"
	.string "If you were to liken it to something\n"
	.string "that you like, what would it be?$"
	.else
	.ifdef GERMAN
	.string "Du kümmerst dich liebevoll um\n"
	.string "{STR_VAR_1}.\p"
	.string "Wenn du es mit etwas vergleichen\n"
	.string "würdest, das du magst, was wäre das?$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_WhatAttractedYouAboutMon:
	.ifdef ENGLISH
	.string "This question also relates to your\n"
	.string "beloved {STR_VAR_1}.\p"
	.string "What was it about {STR_VAR_1} that\n"
	.string "attracted you?$"
	.else
	.ifdef GERMAN
	.string "Diese Frage bezieht sich auch auf dein\n"
	.string "geliebtes {STR_VAR_1}.\p"
	.string "Was hat dich an {STR_VAR_1} angezogen?$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_WhatDoPokemonMeanToYou:
	.ifdef ENGLISH
	.string "Okay, that makes sense.\p"
	.string "The next question might be a little\n"
	.string "on the tough side.\p"
	.string "Here goes…\p"
	.string "What do POKéMON mean to you?$"
	.else
	.ifdef GERMAN
	.string "Okay, das ergibt einen Sinn.\p"
	.string "Diese Frage mag vielleicht etwas schwer\n"
	.string "sein, um sie kurz zu beantworten.\p"
	.string "Also…\p"
	.string "Was bedeuten POKéMON für dich?$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_ThatsAllForInterview:
	.ifdef ENGLISH
	.string "I see!\p"
	.string "Hmhm…\p"
	.string "Okay!\n"
	.string "Thanks for helping me out.\p"
	.string "It was fun and enlightening\n"
	.string "chatting with you.\p"
	.string "It's possible that our interview will\n"
	.string "end up on TV. Tune in and check!\p"
	.string "Okay, that's all.\n"
	.string "Bye-bye!$"
	.else
	.ifdef GERMAN
	.string "Ich verstehe!\p"
	.string "Hmhm…\p"
	.string "Das war’s! Danke, dass du mir deine\n"
	.string "Zeit zur Verfügung gestellt hast!\p"
	.string "Es hat mir viel Spaß gemacht, mich mit\n"
	.string "dir zu unterhalten.\p"
	.string "Vielleicht kannst du dieses Interview\n"
	.string "bald im Fernsehen sehen. Achte darauf!\p"
	.string "Okay, das ist alles.\n"
	.string "Vielen Dank und leb wohl.$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_HereIfYouGetUrgeToTellMe:
	.ifdef ENGLISH
	.string "Oh, okay…\p"
	.string "Well, if you get the urge to tell me\n"
	.string "about POKéMON, I'll be here!$"
	.else
	.ifdef GERMAN
	.string "Oh, okay…\p"
	.string "Nun, wenn du mir doch etwas über\n"
	.string "POKéMON erzählen willst, ich bin hier.$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_EnjoyDoingInterviews:
	.ifdef ENGLISH
	.string "I enjoy this job--you get to learn\n"
	.string "about POKéMON by doing interviews.$"
	.else
	.ifdef GERMAN
	.string "Ich liebe meinen Job - ich lerne so viel\n"
	.string "über POKéMON während der Interviews.$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_InterviewRequest:
	.ifdef ENGLISH
	.string "Hi, you seem to be very close to your\n"
	.string "{STR_VAR_1}.\p"
	.string "Do you know what?\n"
	.string "I'm a TV reporter.\p"
	.string "I travel around interviewing people\n"
	.string "about POKéMON.\p"
	.string "I'm wondering if you'd be willing to tell\n"
	.string "me a little about your {STR_VAR_1}?$"
	.else
	.ifdef GERMAN
	.string "Hallo, du scheinst deinem {STR_VAR_1}\n"
	.string "sehr nahe zu stehen.\p"
	.string "Weißt du was?\n"
	.string "Ich bin ein TV-Reporter.\p"
	.string "Ich reise herum und interviewe Leute,\n"
	.string "befrage sie zu POKéMON.\p"
	.string "Darf ich dich auch etwas über dein\n"
	.string "{STR_VAR_1} fragen?$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_TellMeAnythingAboutYourMon:
	.ifdef ENGLISH
	.string "Wow, thank you!\p"
	.string "Okay, then, please tell me anything\n"
	.string "you'd like about your {STR_VAR_1}.$"
	.else
	.ifdef GERMAN
	.string "Wow, danke schön!\p"
	.string "Dann erzähl mir doch einfach alles, was\n"
	.string "dir an {STR_VAR_1} gefällt.$"
	.endif
	.endif

SlateportCity_PokemonFanClub_Text_ThatsAllForInterview2:
	.ifdef ENGLISH
	.string "Wow…\n"
	.string "That's an interesting account.\p"
	.string "You really are tight with {STR_VAR_1},\n"
	.string "aren't you?\p"
	.string "I get the feeling that your account\n"
	.string "will make a great TV story.\p"
	.string "I promise that I'll turn this into\n"
	.string "an entertaining show.\l"
	.string "Keep your eyes out for it.\p"
	.string "Okay, that's all.\n"
	.string "Bye-bye!$"
	.else
	.ifdef GERMAN
	.string "Wow…\n"
	.string "Das ist ja ein interessanter Bericht.\p"
	.string "Du stehst deinem {STR_VAR_1} sehr nahe,\n"
	.string "nicht wahr?\p"
	.string "Ich denke, dein Bericht wird sich\n"
	.string "großartig im Fernsehen machen.\p"
	.string "Ich verspreche, ich mache daraus eine\n"
	.string "unterhaltsame Sendung. Die darfst\l"
	.string "du nicht verpassen!\p"
	.string "Okay, das war’s.\n"
	.string "Danke und leb wohl.$"
	.endif
	.endif

gTVFanClubOpinionsText00::
	.ifdef ENGLISH
	.string "WE ARE THE POKéMON FAN CLUB!\p"
	.string "We're on the air!\p"
	.string "On this program, we get your opinions,\n"
	.string "and I shout them out on your behalf!\l"
	.string "Isn't it a fantastic program concept?\p"
	.string "Today, we bring you this report from\n"
	.string "our reporter, who we sent out to the\l"
	.string "POKéMON FAN CLUB.\p"
	.string "So, just who is today's featured\n"
	.string "POKéMON fan?\p"
	.string "… … … … … … … …\p"
	.string "{STR_VAR_1}!\p"
	.string "So, let's hear what {STR_VAR_1} has to\n"
	.string "say about {STR_VAR_3} the {STR_VAR_2}.\p"
	.string "And, I will shout those words of love\n"
	.string "out loud on TV!\p"
	.string "Hoo-hah!\p"
	.string "Let's shout!$"
	.else
	.ifdef GERMAN
	.string "WIR SIND DER POKéMON-FANCLUB.\p"
	.string "Wir sind live auf Sendung!\p"
	.string "Hier ist eure Meinung gefragt und ich\n"
	.string "spreche sie öffentlich laut für euch\l"
	.string "aus. Ist das nicht fantastisch?\p"
	.string "Heute bringen wir euch eine Reportage\n"
	.string "unseres Reporters ins Haus, der im Auf-\l"
	.string "trag des POKéMON-FANCLUBs unter-\l"
	.string "wegs war.\p"
	.string "Wer ist heute der glückliche\n"
	.string "POKéMON-Fan, den wir hier vorstellen?\p"
	.string "… … … … … … … …\p"
	.string "{STR_VAR_1}!\p"
	.string "So, was hat uns {STR_VAR_1} wohl über\n"
	.string "{STR_VAR_3}, das {STR_VAR_2},\l"
	.string "zu sagen?\p"
	.string "Und ich… Ich werde die Worte der Zu-\n"
	.string "neigung laut im Fernsehen herausrufen!\p"
	.string "Huuh-haa!\p"
	.string "Lasst uns alle laut rufen!$"
	.endif
	.endif

gTVFanClubOpinionsText01::
	.ifdef ENGLISH
	.string "We asked {STR_VAR_1}, “When you first\n"
	.string "laid eyes on your {STR_VAR_2}, what was\l"
	.string "your initial thought?”\p"
	.string "“{STR_VAR_3}!”\p"
	.string "Yeahah! That's a mighty fine shout!\p"
	.string "Doesn't it bring back memories of those\n"
	.string "days long gone by?$"
	.else
	.ifdef GERMAN
	.string "Wir haben {STR_VAR_1} gefragt: “Als du\n"
	.string "{STR_VAR_2} das erste Mal gesehen hast,\l"
	.string "was war das für ein Gefühl?”\p"
	.string "“{STR_VAR_3}!”\p"
	.string "Juhuhuu! Das ist eine super Aussage!\p"
	.string "Bringt sie euch nicht auch Erinnerungen\n"
	.string "an längst vergangene Zeiten wieder?$"
	.endif
	.endif

gTVFanClubOpinionsText02::
	.ifdef ENGLISH
	.string "We asked {STR_VAR_1}, “If you were to\n"
	.string "liken your {STR_VAR_2} to something,\l"
	.string "it would be…”\p"
	.string "… … … … … … … …\p"
	.string "“{STR_VAR_3}!”\p"
	.string "Whoah-oh, now that's an original idea!\p"
	.string "You sure can sense the intensity of\n"
	.string "feeling the TRAINER has for\l"
	.string "{STR_VAR_2}.$"
	.else
	.ifdef GERMAN
	.string "Wir haben {STR_VAR_1} gefragt: “Wenn du\n"
	.string "{STR_VAR_2} mit etwas vergleichen\l"
	.string "würdest, das du magst, was wäre das?”\p"
	.string "… … … … … … … …\p"
	.string "“{STR_VAR_3}!”\p"
	.string "Huhuhuuu! Was für ein origineller\n"
	.string "Vergleich!\p"
	.string "Man spürt gleich das intensive Gefühl,\n"
	.string "das der TRAINER für {STR_VAR_2}\l"
	.string "empfindet!$"
	.endif
	.endif

gTVFanClubOpinionsText03::
	.ifdef ENGLISH
	.string "And let's see…\n"
	.string "What was it about that {STR_VAR_2}\l"
	.string "that so attracted {STR_VAR_1}?\p"
	.string "… … … … … … … …\p"
	.string "“{STR_VAR_3}!”\p"
	.string "Whoa! Such a spectacular declaration!\p"
	.string "The TRAINER's love for the {STR_VAR_2}\n"
	.string "comes across loud and clear!$"
	.else
	.ifdef GERMAN
	.string "Sehen wir mal weiter…\n"
	.string "Und was genau findet {STR_VAR_1} so\l"
	.string "anziehend an {STR_VAR_2}?\p"
	.string "… … … … … … … …\p"
	.string "“{STR_VAR_3}!”\p"
	.string "Heiaaa! Was für eine spektakuläre\n"
	.string "Erklärung!\p"
	.string "Die Liebe dieses TRAINERs zu seinem\n"
	.string "{STR_VAR_2} wird mehr als deutlich!$"
	.endif
	.endif

gTVFanClubOpinionsText04::
	.ifdef ENGLISH
	.string "Hm? Oh, there's still more.\n"
	.string "Let's check it out!\p"
	.string "Let me see, now…\p"
	.string "We asked {STR_VAR_1}, “What do POKéMON\n"
	.string "mean to you?”\p"
	.string "… … … … … …\p"
	.string "“{STR_VAR_3}!”\p"
	.string "Bravo!\p"
	.string "That's the best shout I've had all day!\p"
	.string "“{STR_VAR_3}!”\p"
	.string "It makes you want to shout it out loud\n"
	.string "again and again!\p"
	.string "Now that we've had a great shout, it's\n"
	.string "time to say good-bye until next time!\p"
	.string "So, let's all have one last shout!\n"
	.string "All together now…\p"
	.string "“{STR_VAR_3}!”$"
	.else
	.ifdef GERMAN
	.string "Hm? Oh, da gibt es noch mehr.\n"
	.string "Dem müssen wir mal nachgehen.\p"
	.string "Lasst uns mal sehen…\p"
	.string "Wir haben {STR_VAR_1} gefragt: “Was be-\n"
	.string "deuten dir POKéMON?”\p"
	.string "… … … … … …\p"
	.string "“{STR_VAR_3}!”\p"
	.string "Bravo!\p"
	.string "Das ist das Beste des heutigen Tages!\p"
	.string "“{STR_VAR_3}!”\p"
	.string "Man will das immer und immer wieder\n"
	.string "laut herausrufen!\p"
	.string "Nach diesem großartigen Ausruf ist es\n"
	.string "auch schon wieder Zeit, sich zu\l"
	.string "verabschieden!\p"
	.string "Also rufen wir jetzt zum Abschluss\n"
	.string "alle zusammen…\p"
	.string "“{STR_VAR_3}!”$"
	.endif
	.endif

gTVFanClubText00::
	.ifdef ENGLISH
	.string "WE ARE THE POKéMON FAN CLUB!\p"
	.string "We're on the air!\p"
	.string "Today, we'll get rolling with the\n"
	.string "POKéMON SURVEY CORNER.\p"
	.string "Out of all the tales woven by POKéMON\n"
	.string "and TRAINERS, what startling new drama\l"
	.string "will grab our attention today?\p"
	.string "Let me see…\p"
	.string "This one!\p"
	.string "We'll start with this letter!\p"
	.string "It's a letter from {STR_VAR_1} about a\n"
	.string "beloved {STR_VAR_2}.\p"
	.string "Let's see how passionately our writer\n"
	.string "can express love for the {STR_VAR_2}!\l"
	.string "Hmhm…$"
	.else
	.ifdef GERMAN
	.string "WIR SIND DER POKéMON-FANCLUB.\p"
	.string "Wir sind live auf Sendung!\p"
	.string "Heute steht unsere Sendung ganz im\n"
	.string "Zeichen unserer POKéMON-UMFRAGE. \p"
	.string "Welcher der Geschichten, die TRAINER\n"
	.string "und POKéMON uns liefern, wird heute\l"
	.string "unsere Aufmerksamkeit gehören?\p"
	.string "Mal sehen…\p"
	.string "Diese hier!\p"
	.string "Wir fangen mit diesem Brief an!\p"
	.string "Dies ist ein Brief von {STR_VAR_1} über\n"
	.string "ein geliebtes {STR_VAR_2}.\p"
	.string "Mal sehen, wie leidenschaftlich der\n"
	.string "Schreiber seine Liebe zu {STR_VAR_2}\l"
	.string "ausdrückt! Hmhm…$"
	.endif
	.endif

gTVFanClubText01::
	.ifdef ENGLISH
	.string "Whoah!\n"
	.string "What an amazing letter!$"
	.else
	.ifdef GERMAN
	.string "Hui!\n"
	.string "Was für ein wunderbarer Brief!$"
	.endif
	.endif

gTVFanClubText02::
	.ifdef ENGLISH
	.string "I loved it, so here it is again!$"
	.else
	.ifdef GERMAN
	.string "Ich liebe ihn, ich muss ihn nochmal\n"
	.string "lesen!$"
	.endif
	.endif

gTVFanClubText03::
	.ifdef ENGLISH
	.string "A great letter bears reading over\n"
	.string "and over!$"
	.else
	.ifdef GERMAN
	.string "Ein großartiger Brief, den man immer und\n"
	.string "immer wieder lesen muss.$"
	.endif
	.endif

gTVFanClubText04::
	.ifdef ENGLISH
	.string "The bit “{STR_VAR_3},” that really\n"
	.string "accentuates emotional impact!\p"
	.string "It's a great letter that has real\n"
	.string "heartfelt depth!$"
	.else
	.ifdef GERMAN
	.string "Dieses kleine “{STR_VAR_3}!” zeigt\n"
	.string "die unglaublich emotionale Bindung!\p"
	.string "Ein großartiger Brief mit einer das Herz\n"
	.string "erwärmenden Tiefe!$"
	.endif
	.endif

gTVFanClubText05::
	.ifdef ENGLISH
	.string "Especially that “{STR_VAR_3}” bit!\p"
	.string "I love how “{STR_VAR_3}” is used!$"
	.else
	.ifdef GERMAN
	.string "Besonders das kleine “{STR_VAR_3}”!\p"
	.string "Ich liebe es, wie “{STR_VAR_3}” hier\n"
	.string "gebraucht wird!$"
	.endif
	.endif

gTVFanClubText06::
	.ifdef ENGLISH
	.string "By the way, and it's not important,\n"
	.string "but “{STR_VAR_3}” is a great saying.\p"
	.string "I've been using “{STR_VAR_3}” a lot\n"
	.string "in conversations lately.$"
	.else
	.ifdef GERMAN
	.string "Übrigens, auch wenn es nicht wirklich\n"
	.string "wichtig ist, “{STR_VAR_3}” ist\l"
	.string "eine super Aussage.\p"
	.string "Ich werde “{STR_VAR_3}” ab sofort in\n"
	.string "meiner Konversation einsetzen.$"
	.endif
	.endif

gTVFanClubText07::
	.ifdef ENGLISH
	.string "If I had to score this letter,\n"
	.string "I'd give it {STR_VAR_3} points.\p"
	.string "Next time, I'll be expecting an even\n"
	.string "better letter, {STR_VAR_1}!\p"
	.string "A-whoops, will you look at the time?\n"
	.string "Time to say good-bye until next time!$"
	.else
	.ifdef GERMAN
	.string "Wenn ich diesen Brief bewerten müsste,\n"
	.string "bekäme er {STR_VAR_3} Punkte von mir.\p"
	.string "Und für das nächste Mal erwarte ich\n"
	.string "einen noch besseren Brief, {STR_VAR_1}!\p"
	.string "Hui je, schaut euch nur die Uhrzeit an!\n"
	.string "Für heute sage ich Tschüss. Bis zum\l"
	.string "nächsten Mal.$"
	.endif
	.endif

SlateportCity_OceanicMuseum_1F_Text_InterviewRequest:
	.ifdef ENGLISH
	.string "Oh?\n"
	.string "Do you perhaps like POKéMON?\p"
	.string "I'm on assignment with the TV network.\p"
	.string "I'm gathering stories on POKéMON and\n"
	.string "TRAINERS that occurred recently.\p"
	.string "If you don't mind, could you tell me\n"
	.string "something about yourself?$"
	.else
	.ifdef GERMAN
	.string "Ach!\n"
	.string "Magst du vielleicht POKéMON?\p"
	.string "Ich habe einen Vertrag mit einem Fern-\n"
	.string "sehsender.\p"
	.string "Ich sammle aktuelle Geschichten von\n"
	.string "POKéMON und ihren TRAINERn.\p"
	.string "Hättest du Lust, mir etwas von dir zu\n"
	.string "erzählen?$"
	.endif
	.endif

SlateportCity_OceanicMuseum_1F_Text_InterviewRequestShort:
	.ifdef ENGLISH
	.string "I'm gathering stories on POKéMON and\n"
	.string "TRAINERS that occurred recently.\p"
	.string "If you don't mind, could you tell me\n"
	.string "something about yourself?$"
	.else
	.ifdef GERMAN
	.string "Ich sammle aktuelle Geschichten von\n"
	.string "POKéMON und ihren TRAINERn.\p"
	.string "Hättest du Lust, mir etwas von dir zu\n"
	.string "erzählen?$"
	.endif
	.endif

SlateportCity_OceanicMuseum_1F_Text_TellMeExperienceInvolvingPokemon:
	.ifdef ENGLISH
	.string "Oh, you will?\n"
	.string "Thank you!\p"
	.string "Then, please, tell me anything of\n"
	.string "interest that you experienced recently\l"
	.string "involving POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Oh, du hast Lust dazu?!?\n"
	.string "Wunderbar! Danke schön!\p"
	.string "Dann erzähl mir doch bitte von\n"
	.string "interessanten Begebenheiten, in denen\l"
	.string "POKéMON eine Rolle spielen.$"
	.endif
	.endif

SlateportCity_OceanicMuseum_1F_Text_LetMeKnowIfYouHaveStory:
	.ifdef ENGLISH
	.string "Oh, I see…\p"
	.string "Well, if you do have an interesting\n"
	.string "story to tell, please let me know.$"
	.else
	.ifdef GERMAN
	.string "Oh, ich versteh’ schon…\p"
	.string "Nun, wenn du mir eine interessante\n"
	.string "Geschichte erzählen kannst, sag es mir.$"
	.endif
	.endif

SlateportCity_OceanicMuseum_1F_Text_ThatsAllForInterview:
	.ifdef ENGLISH
	.string "Oh, what an uplifting story!\p"
	.string "I'll be sure to get your story told\n"
	.string "on television.\p"
	.string "It should be aired sometime, I think,\n"
	.string "so please look forward to it.$"
	.else
	.ifdef GERMAN
	.string "Hach, eine erhebende Geschichte!\p"
	.string "Ich bin sicher, deine Geschichte wird\n"
	.string "im Fernsehen ausgestrahlt.\p"
	.string "Irgendwann bestimmt. Also, verpasse\n"
	.string "sie nicht!$"
	.endif
	.endif

SlateportCity_OceanicMuseum_1F_Text_BetterWriteUpStory:
	.ifdef ENGLISH
	.string "Hmmm…\n"
	.string "I've got a good story for a TV program.\p"
	.string "I'd better write it up in a hurry!$"
	.else
	.ifdef GERMAN
	.string "Hmmm… Da habe ich eine wirklich gute\n"
	.string "Geschichte für das Fernsehprogramm.\p"
	.string "Ich sollte sie schnell aufschreiben!$"
	.endif
	.endif

gTVRecentHappeningsText00::
	.ifdef ENGLISH
	.string "Hello, it's time for RECENT HAPPENINGS.\p"
	.string "For POKéMON TRAINERS, every day\n"
	.string "is a storybook tale.\p"
	.string "What we want to do is to introduce you\n"
	.string "to some of these POKéMON tales.\p"
	.string "Today, we bring you the story\n"
	.string "of the TRAINER {STR_VAR_1}.\p"
	.string "What did {STR_VAR_1} experience recently?\n"
	.string "Let's find out.\p"
	.string "Let's see…$"
	.else
	.ifdef GERMAN
	.string "Hallo, es ist Zeit für INTERESSANTE\n"
	.string "GESCHICHTEN.\p"
	.string "Für einen POKéMON-TRAINER ist jeder\n"
	.string "Tag ein Tag voller Geschichten.\p"
	.string "Wir möchten heute einige dieser \n"
	.string "POKéMON-Geschichten erzählen.\p"
	.string "Heute erzählen wir die Geschichte von\n"
	.string "TRAINER {STR_VAR_1}.\p"
	.string "Was mag {STR_VAR_1} wohl erlebt haben?\n"
	.string "Lasst es uns herausfinden.\p"
	.string "Mal sehen…$"
	.endif
	.endif

gTVRecentHappeningsText01::
	.ifdef ENGLISH
	.string "Wasn't that enlightening?\p"
	.string "The story gives you a clear idea of what\n"
	.string "{STR_VAR_1} has experienced recently.\l"
	.string "It's as if we were there as witnesses!$"
	.else
	.ifdef GERMAN
	.string "War das nicht aufschlussreich?\p"
	.string "Diese Geschichte gibt genau wieder, was\n"
	.string "{STR_VAR_1} vor kurzem erlebt hat. So, als\l"
	.string "hätten wir es selber erlebt.$"
	.endif
	.endif

gTVRecentHappeningsText02::
	.ifdef ENGLISH
	.string "“{STR_VAR_3}.” That\n"
	.string "accents the tale and gives it depth.$"
	.else
	.ifdef GERMAN
	.string "“{STR_VAR_3}.” Das gibt\n"
	.string "der Geschichte Akzente und Tiefe.$"
	.endif
	.endif

gTVRecentHappeningsText03::
	.ifdef ENGLISH
	.string "“{STR_VAR_3}.”\n"
	.string "That gives the tale a sense of place.\l"
	.string "It lets us envision the tale's setting.$"
	.else
	.ifdef GERMAN
	.string "“{STR_VAR_3}.” Das gibt\n"
	.string "uns einen Eindruck von dem Schauplatz.\l"
	.string "Wir können uns alles besser vorstellen.$"
	.endif
	.endif

gTVRecentHappeningsText04::
	.ifdef ENGLISH
	.string "The “{STR_VAR_3}”\n"
	.string "section of the tale is very expressive.$"
	.else
	.ifdef GERMAN
	.string "“{STR_VAR_3}” war die\n"
	.string "eindrucksvollste Stelle der Geschichte.$"
	.endif
	.endif

gTVRecentHappeningsText05::
	.ifdef ENGLISH
	.string "{STR_VAR_1} has recounted a wonderful\n"
	.string "tale involving POKéMON.\p"
	.string "And now {STR_VAR_1}'s tale is indelibly\n"
	.string "etched into your soul, too.\p"
	.string "That's it for today.\n"
	.string "Please tune in next time.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} hat uns eine wundervolle Ge-\n"
	.string "schichte mit POKéMON erzählt.\p"
	.string "Und nun hat sich diese Geschichte tief\n"
	.string "in unsere Seelen eingebrannt.\p"
	.string "Das war es für heute. Bitte schaltet\n"
	.string "auch nächstes Mal wieder ein.$"
	.endif
	.endif

gTVMassOutbreakText00::
	.ifdef ENGLISH
	.string "Greetings!\n"
	.string "It's time for POKéMON NEWS.\p"
	.string "We've just received word of a very\n"
	.string "rare occurrence.\p"
	.string "There have been reports of a mass\n"
	.string "outbreak of {STR_VAR_2} in the vicinity\l"
	.string "of {STR_VAR_1}.\p"
	.string "{STR_VAR_2}, as you're probably aware,\n"
	.string "is known as a POKéMON that's rare\l"
	.string "and hard to find.\p"
	.string "It sounds like a rare opportunity to\n"
	.string "see the mystifying outbreak of\l"
	.string "{STR_VAR_2} in the wild.\p"
	.string "That's the news on POKéMON NEWS.$"
	.else
	.ifdef GERMAN
	.string "Guten Tag, meine Damen und Herren!\n"
	.string "Hier sind die POKéMON NACHRICHTEN.\p"
	.string "Wir haben soeben von einem sehr\n"
	.string "seltenen Ereignis erfahren.\p"
	.string "Es wird berichtet, dass es in der Umge-\n"
	.string "bung von {STR_VAR_1} zu einem Massen-\l"
	.string "aufkommen von {STR_VAR_2} kam.\p"
	.string "{STR_VAR_2}, das ist bestimmt jedem be-\n"
	.string "kannt, ist ein seltenes POKéMON,\l"
	.string "das nur sehr schwer zu finden ist.\p"
	.string "Das scheint eine seltene Gelegenheit\n"
	.string "zu sein, den Ausbruch von wilden\l"
	.string "{STR_VAR_2} zu beobachten.\p"
	.string "Das waren die POKéMON NACHRICHTEN.$"
	.endif
	.endif

gTV3CheersForPokeblocksText00::
	.ifdef ENGLISH
	.string "MC: We hope you're in good cheer,\n"
	.string "“3 CHEERS FOR {POKEBLOCK}S” is here!\p"
	.string "Today, we examine the {POKEBLOCK} blended\n"
	.string "by {STR_VAR_1} and associates.\p"
	.string "Without any delay, let me feed it\n"
	.string "to my gourmet POKéMON GULPIN.\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"
	.else
	.ifdef GERMAN
	.string "MC: Ich hoffe, ihr seid in Topstimmung!\n"
	.string "“3 HOCHS FÜR DIE {POKEBLOCK}!”\p"
	.string "Heute untersuchen wir {POKEBLOCK}, die\n"
	.string "von {STR_VAR_1} und Freunden\l"
	.string "hergestellt wurden.\p"
	.string "Und ohne weitere Verzögerung werden\n"
	.string "wir sie meinem SCHLUPPUCK, einem\l"
	.string "wahren Feinschmecker, geben.\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…$"
	.endif
	.endif

gTV3CheersForPokeblocksText01::
	.ifdef ENGLISH
	.string "GULPIN: Gubi! Gubii!\p"
	.string "MC: And the verdict is very {STR_VAR_1}!\n"
	.string "GULPIN says it tastes “{STR_VAR_2}!”\p"
	.string "Thank you so much, {STR_VAR_3}!$"
	.else
	.ifdef GERMAN
	.string "SCHLUPPUCK: Schlupp! Puck!\p"
	.string "MC: Er scheint sehr {STR_VAR_1} zu sein.\n"
	.string "SCHLUPPUCK meint, er schmeckt\l"
	.string "“{STR_VAR_2}!”\p"
	.string "Vielen Dank, {STR_VAR_3}!$"
	.endif
	.endif

gTV3CheersForPokeblocksText02::
	.ifdef ENGLISH
	.string "{STR_VAR_1}'s blending performance\n"
	.string "left something to be desired.\p"
	.string "If this TRAINER could blend better,\n"
	.string "the {POKEBLOCK} would be much tastier.$"
	.else
	.ifdef GERMAN
	.string "Das Talent von {STR_VAR_1} beim\n"
	.string "Beerenmixen könnte besser sein.\p"
	.string "Wäre dieser TRAINER besser, würden\n"
	.string "auch die {POKEBLOCK} besser schmecken.$"
	.endif
	.endif

gTV3CheersForPokeblocksText03::
	.ifdef ENGLISH
	.string "GULPIN: Gubi! Gubii!\p"
	.string "MC: Hmm… It's too {STR_VAR_1}.\n"
	.string "GULPIN says it tastes “{STR_VAR_2}!”\p"
	.string "It looks like {STR_VAR_3}'s errors\n"
	.string "hurt the blending quality…$"
	.else
	.ifdef GERMAN
	.string "SCHLUPPUCK: Schlupp! Puck!\p"
	.string "MC: Er scheint sehr {STR_VAR_1} zu sein.\n"
	.string "SCHLUPPUCK meint, er schmeckt\l"
	.string "“{STR_VAR_2}!”\p"
	.string "{STR_VAR_3} hat Fehler gemacht, die die\n"
	.string "Qualität beeinflussen.$"
	.endif
	.endif

gTV3CheersForPokeblocksText04::
	.ifdef ENGLISH
	.string "It's too bad that {STR_VAR_1}'s\n"
	.string "leading effort went to waste.\p"
	.string "Let's hope {STR_VAR_2} can turn in\n"
	.string "a better showing next time!$"
	.else
	.ifdef GERMAN
	.string "Schade, dass die Bemühungen von\n"
	.string "{STR_VAR_1} umsonst waren.\p"
	.string "Und auch {STR_VAR_2} sollte beim\n"
	.string "nächsten Mal eine bessere Leistung\l"
	.string "zeigen.$"
	.endif
	.endif

gTV3CheersForPokeblocksText05::
	.ifdef ENGLISH
	.string "Tune in next time!\n"
	.string "Our slogan is “3 CHEERS FOR {POKEBLOCK}S!”$"
	.else
	.ifdef GERMAN
	.string "Freut euch auf die nächste Sendung!\n"
	.string "Unsere Devise lautet\l"
	.string "“3 HOCHS FÜR DIE {POKEBLOCK}!”$"
	.endif
	.endif

LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer::
	.ifdef ENGLISH
	.string "Hi, there!\p"
	.string "I'm a big fan of {STR_VAR_1}.\n"
	.string "What's your opinion of {STR_VAR_1}?$"
	.else
	.ifdef GERMAN
	.string "Hey, du da!\p"
	.string "Ich bin ein großer Fan von {STR_VAR_1}.\n"
	.string "Was hältst du von {STR_VAR_1}?$"
	.endif
	.endif

LilycoveCity_PokemonTrainerFanClub_Text_ThatsWhatYouThink::
	.ifdef ENGLISH
	.string "I see, I see. That's what you think\n"
	.string "about the TRAINER.$"
	.else
	.ifdef GERMAN
	.string "Ah ha. Das ist also deine Meinung über\n"
	.string "diesen TRAINER.$"
	.endif
	.endif

LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer::
	.ifdef ENGLISH
	.string "Have you completely forgotten\n"
	.string "about {STR_VAR_1}?$"
	.else
	.ifdef GERMAN
	.string "Du erinnerst dich gar nicht mehr an\n"
	.string "{STR_VAR_1}?$"
	.endif
	.endif

LilycoveCity_PokemonTrainerFanClub_Text_WhatsYourOpinionOfTrainer2::
	.ifdef ENGLISH
	.string "I'm a big fan of {STR_VAR_1}.\n"
	.string "What's your opinion of {STR_VAR_1}?$"
	.else
	.ifdef GERMAN
	.string "Ich bin ein großer Fan von {STR_VAR_1}.\n"
	.string "Was hältst du von {STR_VAR_1}?$"
	.endif
	.endif

LilycoveCity_PokemonTrainerFanClub_Text_HowStrongRateTrainer::
	.ifdef ENGLISH
	.string "How strong would you rate {STR_VAR_1}\n"
	.string "on a scale of one hundred?$"
	.else
	.ifdef GERMAN
	.string "Für wie stark würdest du {STR_VAR_1}\n"
	.string "auf einer Skala von 0 bis 100 halten?$"
	.endif
	.endif

LilycoveCity_PokemonTrainerFanClub_Text_HaveYouForgottenTrainer2::
	.ifdef ENGLISH
	.string "Have you completely forgotten\n"
	.string "about {STR_VAR_1}?$"
	.else
	.ifdef GERMAN
	.string "Du erinnerst dich gar nicht mehr an\n"
	.string "{STR_VAR_1}?$"
	.endif
	.endif

LilycoveCity_PokemonTrainerFanClub_Text_YouShouldMeetTrainer::
	.ifdef ENGLISH
	.string "Oh, I see!\n"
	.string "You should meet {STR_VAR_1} sometime.\l"
	.string "I'm sure you'll become a fan, too!$"
	.else
	.ifdef GERMAN
	.string "Ach so! Ich hoffe, du triffst\n"
	.string "{STR_VAR_1} irgendwann mal. Dann wirst\l"
	.string "du bestimmt auch ein Fan.$"
	.endif
	.endif

LilycoveCity_PokemonTrainerFanClub_Text_ThankYouIllShareThisInfo::
	.ifdef ENGLISH
	.string "I see, I see.\p"
	.string "Thank you!\n"
	.string "That's very useful to know.\p"
	.string "I'll share this information with other\n"
	.string "{STR_VAR_1} fans and discuss it.$"
	.else
	.ifdef GERMAN
	.string "Ah ha.\p"
	.string "Vielen Dank!\n"
	.string "Das war interessant.\p"
	.string "Ich werde das anderen Fans von\n"
	.string "{STR_VAR_1} mitteilen und mit ihnen\l"
	.string "darüber diskutieren.$"
	.endif
	.endif

LilycoveCity_PokemonTrainerFanClub_HopeYouCatchTVSpecial::
	.ifdef ENGLISH
	.string "There's going to be a TV special on\n"
	.string "{STR_VAR_1} very soon.\p"
	.string "I hope you catch it!$"
	.else
	.ifdef GERMAN
	.string "Im Fernsehen zeigen sie bald eine\n"
	.string "Sondersendung über {STR_VAR_1}.\p"
	.string "Die darf ich auf keinen Fall verpassen!$"
	.endif
	.endif

gTVTrainerFanClubSpecialText00::
	.ifdef ENGLISH
	.string "TRAINER FAN CLUB\n"
	.string "{STR_VAR_1} SPECIAL!\p"
	.string "This is a special presentation for\n"
	.string "the fans of {STR_VAR_1} all over HOENN!\p"
	.string "Today, we ask the question, “What do\n"
	.string "people think of {STR_VAR_1}?”\p"
	.string "We posed the question to {STR_VAR_2}\n"
	.string "as the TRAINER representative.\p"
	.string "We asked, “In one word, how would\n"
	.string "you describe {STR_VAR_1}?”\p"
	.string "The reply: “{STR_VAR_3}.”\p"
	.string "Kudos to {STR_VAR_2}!\n"
	.string "What a perceptive opinion!\p"
	.string "“{STR_VAR_3} {STR_VAR_1}.”\n"
	.string "It has such a nice ring to it!\p"
	.string "{STR_VAR_2} also scored {STR_VAR_1}'s\n"
	.string "strength from 0 to 100.$"
	.else
	.ifdef GERMAN
	.string "POKéMON TRAINER-FANCLUB\n"
	.string "SONDERSENDUNG ÜBER {STR_VAR_1}!\p"
	.string "Heute bieten wir allen Fans in HOENN, \n"
	.string "die {STR_VAR_1} bewundern, etwas\l"
	.string "Besonderes!\p"
	.string "Wir haben uns die Frage gestellt: “Was\n"
	.string "denken die Leute über {STR_VAR_1}?”\p"
	.string "Wir fragten repräsentativ den TRAINER\n"
	.string "{STR_VAR_2}.\p"
	.string "Unsere Frage: “Wie würdest du\n"
	.string "{STR_VAR_1} mit einem Wort\l"
	.string "beschreiben?”\p"
	.string "Die Antwort: “{STR_VAR_3}.”\p"
	.string "Wunderbar, {STR_VAR_2}!\n"
	.string "Was für eine scharfsinnige Antwort.\p"
	.string "“{STR_VAR_3} {STR_VAR_1}.”\n"
	.string "Eine treffende Beschreibung.\p"
	.string "{STR_VAR_2} legte die Stärke von\n"
	.string "{STR_VAR_1} auf einer Skala von\l"
	.string "1 bis 100 fest.$"
	.endif
	.endif

gTVTrainerFanClubSpecialText01::
	.ifdef ENGLISH
	.string "The score was {STR_VAR_3} points!\n"
	.string "That is a very high score indeed!\p"
	.string "{STR_VAR_2} must obviously hold\n"
	.string "{STR_VAR_1} in very high esteem.$"
	.else
	.ifdef GERMAN
	.string "Sie liegt bei {STR_VAR_3}!\n"
	.string "Eine sehr hohe Zahl!\p"
	.string "{STR_VAR_2} scheint {STR_VAR_1}\n"
	.string "sehr zu schätzen und zu bewundern.$"
	.endif
	.endif

gTVTrainerFanClubSpecialText02::
	.ifdef ENGLISH
	.string "The score was {STR_VAR_3} points!\n"
	.string "That is quite a good score.\p"
	.string "{STR_VAR_2} must consider\n"
	.string "{STR_VAR_1} to be a rival.$"
	.else
	.ifdef GERMAN
	.string "Sie liegt bei {STR_VAR_3}!\n"
	.string "Ein guter Wert!\p"
	.string "{STR_VAR_2} sieht in {STR_VAR_1}\n"
	.string "anscheinend einen Rivalen.$"
	.endif
	.endif

gTVTrainerFanClubSpecialText03::
	.ifdef ENGLISH
	.string "The score was {STR_VAR_3} points!\n"
	.string "That's a rather weak score.\p"
	.string "{STR_VAR_2} must consider\n"
	.string "{STR_VAR_1} to be a mere sidekick.$"
	.else
	.ifdef GERMAN
	.string "Sie liegt bei {STR_VAR_3}!\n"
	.string "Nicht gerade beeindruckend.\p"
	.string "{STR_VAR_2} hält {STR_VAR_1}\n"
	.string "wohl für einen TRAINER, der nur\l"
	.string "zufällig Kämpfe gewinnt.$"
	.endif
	.endif

gTVTrainerFanClubSpecialText04::
	.ifdef ENGLISH
	.string "The score was {STR_VAR_3} point(s)!\n"
	.string "That's a terrible score.\p"
	.string "{STR_VAR_2} must consider\n"
	.string "{STR_VAR_1} to be an underling.$"
	.else
	.ifdef GERMAN
	.string "Sie liegt bei {STR_VAR_3}!\n"
	.string "Was für eine Blamage…\p"
	.string "{STR_VAR_2} scheint von {STR_VAR_1}\n"
	.string "gar nichts zu halten.$"
	.endif
	.endif

gTVTrainerFanClubSpecialText05::
	.ifdef ENGLISH
	.string "There you have it, folks!\p"
	.string "I think we all learned something\n"
	.string "new about {STR_VAR_1}.\p"
	.string "In closing, I'll leave you with\n"
	.string "{STR_VAR_2}'s words.\p"
	.string "{STR_VAR_3} {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Das war’s, Leute!\p"
	.string "Ich bin sicher, wir haben viel Neues \n"
	.string "über {STR_VAR_1} erfahren.\p"
	.string "Ich verabschiede mich mit den Worten\n"
	.string "von {STR_VAR_2}.\p"
	.string "{STR_VAR_3} {STR_VAR_1}!$"
	.endif
	.endif

gTVNameRaterText00::
	.ifdef ENGLISH
	.string "And now, it's time for…\n"
	.string "THE NAME RATER SHOW.\p"
	.string "I tell your POKéMON's fortune from\n"
	.string "the nickname you've bestowed.\p"
	.string "Advice is what I have to give, and it is\n"
	.string "helpful advice that I offer.\p"
	.string "Today, I shall do a reading of\n"
	.string "the nickname {STR_VAR_3} of {STR_VAR_1}'s\l"
	.string "POKéMON {STR_VAR_2}.\p"
	.string "Hmhm…\p"
	.string "Hmm…\n"
	.string "This nickname is…$"
	.else
	.ifdef GERMAN
	.string "Und nun ist es wieder Zeit für…\n"
	.string "DIE NAMENBEWERTER SHOW\p"
	.string "Ich sage die Zukunft eures POKéMON\n"
	.string "anhand seines Kosenamens vorher.\p"
	.string "Ratschläge habe ich zu geben und\n"
	.string "hilfreiche Ratschläge biete ich an.\p"
	.string "Heute basiert meine Prophezeiung auf\n"
	.string "dem Kosenamen {STR_VAR_3} des\l"
	.string "POKéMON {STR_VAR_2} von {STR_VAR_1}.\p"
	.string "Hmhm…\p"
	.string "Hmm…\n"
	.string "Dieser Kosename…$"
	.endif
	.endif

gTVNameRaterText01::
	.ifdef ENGLISH
	.string "A nickname that hints at talent in many\n"
	.string "different ways.\p"
	.string "I urge this TRAINER to take courage\n"
	.string "and take on many challenges.$"
	.else
	.ifdef GERMAN
	.string "Ein Kosename, der auf ein vielfältiges\n"
	.string "Talent hindeutet.\p"
	.string "Ich rate dem TRAINER, mutig zu sein\n"
	.string "und sich vielen Herausforderungen\l"
	.string "zu stellen.$"
	.endif
	.endif

gTVNameRaterText02::
	.ifdef ENGLISH
	.string "A nickname that perfectly complements\n"
	.string "{STR_VAR_1}, the TRAINER's name.\p"
	.string "It suggests that you will forge a fine\n"
	.string "partnership with precise timing.$"
	.else
	.ifdef GERMAN
	.string "Dieser Kosename passt perfekt\n"
	.string "zu {STR_VAR_1}, dem Namen des TRAINERs!\p"
	.string "Ich sehe eine starke Partnerschaft, in\n"
	.string "der das Timing perfekt ist.$"
	.endif
	.endif

gTVNameRaterText03::
	.ifdef ENGLISH
	.string "A nickname fit for a unique individual\n"
	.string "of a POKéMON!\p"
	.string "If raised properly, this POKéMON's\n"
	.string "uniqueness will bloom excessively!$"
	.else
	.ifdef GERMAN
	.string "Dieser Kosename betont die einzig-\n"
	.string "artige Persönlichkeit des POKéMON.\p"
	.string "Wird das POKéMON gut aufgezogen, ent-\n"
	.string "wickelt sich seine Einzigartigkeit voll.$"
	.endif
	.endif

gTVNameRaterText04::
	.ifdef ENGLISH
	.string "A nickname that will nurture the caring\n"
	.string "and compassionate side of POKéMON.\p"
	.string "If raised properly, this POKéMON will\n"
	.string "come to exhibit real warmth!$"
	.else
	.ifdef GERMAN
	.string "Dieser Kosename zeigt die mitfühlende\n"
	.string "und fürsorgliche Seite der POKéMON.\p"
	.string "Wird dieses POKéMON gut aufgezogen,\n"
	.string "wird es sehr warmherzig sein!$"
	.endif
	.endif

gTVNameRaterText05::
	.ifdef ENGLISH
	.string "A very fine nickname that hints at\n"
	.string "greatness to come.\p"
	.string "I am intrigued about what the future\n"
	.string "holds in store for this POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Ein schöner Kosename, der auf die\n"
	.string "zukünftige Größe hindeutet.\p"
	.string "Mich würde es schon interessieren, was\n"
	.string "die Zukunft für dieses POKéMON bringt.$"
	.endif
	.endif

gTVNameRaterText06::
	.ifdef ENGLISH
	.string "A good nickname that should make the\n"
	.string "POKéMON hale and hearty!\p"
	.string "That POKéMON should remain fit and\n"
	.string "robust for a long, long time.$"
	.else
	.ifdef GERMAN
	.string "Dieser gute Kosename sollte das\n"
	.string "POKéMON kräftig und herzlich\l"
	.string "werden lassen!\p"
	.string "Dieses POKéMON wird für lange, lange\n"
	.string "Zeit gesund und fit sein.$"
	.endif
	.endif

gTVNameRaterText07::
	.ifdef ENGLISH
	.string "A good nickname that should make the\n"
	.string "POKéMON very active!\p"
	.string "I should think that this POKéMON will be\n"
	.string "a strong performer in battles.$"
	.else
	.ifdef GERMAN
	.string "Dieser gute Kosename sollte das\n"
	.string "POKéMON sehr aktiv machen!\p"
	.string "Ich denke, das POKéMON wird in\n"
	.string "Kämpfen stark auftreten.$"
	.endif
	.endif

gTVNameRaterText08::
	.ifdef ENGLISH
	.string "An appealing nickname that should make\n"
	.string "the POKéMON very charming!\p"
	.string "I don't doubt that this POKéMON will be\n"
	.string "quite the charmer in POKéMON CONTESTS.$"
	.else
	.ifdef GERMAN
	.string "Ein ansprechender Kosename, der dem\n"
	.string "POKéMON Charme verleihen wird!\p"
	.string "Ich bezweifle nicht, dass das POKéMON\n"
	.string "in einem POKéMON WETTBEWERB alle\l"
	.string "mit seinem Charme betören wird!$"
	.endif
	.endif

gTVNameRaterText09::
	.ifdef ENGLISH
	.string "The nickname {STR_VAR_1} is rooted by\n"
	.string "the letter “{STR_VAR_3}.”\p"
	.string "That letter is supported by the first\n"
	.string "letter “{STR_VAR_2},” which gives it a solid sense\l"
	.string "of presence as a nickname.$"
	.else
	.ifdef GERMAN
	.string "Der Kosename {STR_VAR_1} wurzelt in\n"
	.string "dem Buchstaben “{STR_VAR_3}”.\p"
	.string "Der Buchstabe wird noch verstärkt\n"
	.string "durch den Anfangsbuchstaben “{STR_VAR_2}”,\p"
	.string "wodurch der Kosename eine starke\n"
	.string "Ausstrahlung bekommt.$"
	.endif
	.endif

gTVNameRaterText10::
	.ifdef ENGLISH
	.string "The nickname {STR_VAR_1} is very\n"
	.string "shapely in a pleasing manner.\p"
	.string "The presence of the letters “{STR_VAR_2}” and\n"
	.string "“{STR_VAR_3}”--now that is remarkably good!$"
	.else
	.ifdef GERMAN
	.string "Der Kosename {STR_VAR_1} ist auf \n"
	.string "ansprechende Weise wohlklingend.\p"
	.string "Die Ausstrahlung der Buchstaben “{STR_VAR_2}”\n"
	.string "und “{STR_VAR_3}” - einfach bemerkenswert!$"
	.endif
	.endif

gTVNameRaterText11::
	.ifdef ENGLISH
	.string "The nickname {STR_VAR_1}--it has a\n"
	.string "sublime, flowing feel to it.\p"
	.string "The flow from the initial letter “{STR_VAR_2}” to\n"
	.string "“{STR_VAR_3}” is especially wonderful.$"
	.else
	.ifdef GERMAN
	.string "Der Kosename {STR_VAR_1} - er strahlt\n"
	.string "ein sublimes, fließendes Gefühl aus.\p"
	.string "Der Fluss des ersten Buchstabens “{STR_VAR_2}”\n"
	.string "bis hin zum “{STR_VAR_3}” ist wunderbar.$"
	.endif
	.endif

gTVNameRaterText12::
	.ifdef ENGLISH
	.string "Let's examine other examples of fine\n"
	.string "nicknames, shall we?$"
	.else
	.ifdef GERMAN
	.string "Lasst uns weitere Beispiele für gute\n"
	.string "Kosenamen untersuchen.$"
	.endif
	.endif

gTVNameRaterText13::
	.ifdef ENGLISH
	.string "Try this example. Take a part of the\n"
	.string "TRAINER name of {STR_VAR_1}, and end\l"
	.string "up with the fine nickname {STR_VAR_2}{STR_VAR_3}.$"
	.else
	.ifdef GERMAN
	.string "Nehmen wir zum Beispiel einen Teil des\n"
	.string "Namens von TRAINER {STR_VAR_1}. Wir er-\l"
	.string "halten den schönen Kosenamen {STR_VAR_2}{STR_VAR_3}.$"
	.endif
	.endif

gTVNameRaterText14::
	.ifdef ENGLISH
	.string "The nickname {STR_VAR_2}{STR_VAR_3} would also work\n"
	.string "quite well.$"
	.else
	.ifdef GERMAN
	.string "Natürlich wäre der Kosename {STR_VAR_2}{STR_VAR_3}\n"
	.string "genauso schön.$"
	.endif
	.endif

gTVNameRaterText15::
	.ifdef ENGLISH
	.string "The POKéMON's species name of\n"
	.string "{STR_VAR_2} could be used as the basis\l"
	.string "for making the nickname {STR_VAR_1}{STR_VAR_3}.$"
	.else
	.ifdef GERMAN
	.string "Der Name der POKéMON-Kategorie\n"
	.string "{STR_VAR_2} kann ebenfalls als Basis\l"
	.string "für den Kosenamen {STR_VAR_1}{STR_VAR_3} dienen.$"
	.endif
	.endif

gTVNameRaterText16::
	.ifdef ENGLISH
	.string "{STR_VAR_1}{STR_VAR_3} would also be an effective\n"
	.string "nickname.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1}{STR_VAR_3} ist ebenfalls ein anziehender\n"
	.string "Kosename.$"
	.endif
	.endif

gTVNameRaterText17::
	.ifdef ENGLISH
	.string "What should always be avoided is using\n"
	.string "another POKéMON species name.\p"
	.string "For instance, avoid taking the name of\n"
	.string "{STR_VAR_2} to make the nickname {STR_VAR_1}{STR_VAR_3}.\l"
	.string "That is unacceptable.$"
	.else
	.ifdef GERMAN
	.string "Man sollte niemals einem POKéMON die\n"
	.string "Kategoriebezeichnung eines anderen\l"
	.string "POKéMON als Kosenamen geben!\p"
	.string "Zum Beispiel sollte der Name von\n"
	.string "{STR_VAR_2} nicht für den Namen {STR_VAR_1}{STR_VAR_3}\l"
	.string "verwendet werden.$"
	.endif
	.endif

gTVNameRaterText18::
	.ifdef ENGLISH
	.string "I must say that {STR_VAR_1} is quite\n"
	.string "a good nickname.\p"
	.string "I hope that the TRAINER will continue\n"
	.string "to treat {STR_VAR_1} with love.\p"
	.string "That's it for today's show.\n"
	.string "May we meet again.$"
	.else
	.ifdef GERMAN
	.string "Aber ich gebe zu, {STR_VAR_1}\n"
	.string "ist wirklich ein guter Kosename.\p"
	.string "Und ich hoffe, dass der TRAINER\n"
	.string "{STR_VAR_1} weiter liebevoll behandelt.\p"
	.string "Das war unsere heutige Show.\n"
	.string "Wir sehen uns hoffentlich bald wieder.$"
	.endif
	.endif

gTVPokemonAnglerText00::
	.ifdef ENGLISH
	.string "{STR_VAR_2} ANGLER\p"
	.string "ANNOUNCER: Hello! Today, we'll get tips\n"
	.string "on fishing for {STR_VAR_2}.\p"
	.string "GURU, what advice can you give for\n"
	.string "catching {STR_VAR_2}?\p"
	.string "GURU: Hm? Catching {STR_VAR_2}?\n"
	.string "Well, let me tell you, be patient and\l"
	.string "wait. That's the bottom line.\p"
	.string "Do you see {STR_VAR_1} over there?\n"
	.string "That TRAINER makes a good example.\p"
	.string "That TRAINER's already had\n"
	.string "{STR_VAR_3} POKéMON get away.\p"
	.string "But there {STR_VAR_1} waits. No giving up.\n"
	.string "That's the law for catching {STR_VAR_2}.\p"
	.string "ANNOUNCER: I see…\p"
	.string "Oh! {STR_VAR_1} has finally landed an\n"
	.string "elusive {STR_VAR_2}!\p"
	.string "The TRAINER appears close to tears\n"
	.string "out of sheer joy!\p"
	.string "Seeing that elated look, I'm getting\n"
	.string "the itch to go fishing, too!\p"
	.string "Viewers, why not take this as a cue to\n"
	.string "try some {STR_VAR_2} fishing?\p"
	.string "Until our next broadcast, farewell and\n"
	.string "good fishing to you all!$"
	.else
	.ifdef GERMAN
	.string " {STR_VAR_2}-ANGLER\p"
	.string "MODERATOR: Hallo! Heute gibt es\n"
	.string "Tipps zum Angeln von {STR_VAR_2}.\p"
	.string "GURU, welchen Ratschlag haben\n"
	.string "Sie für uns?\p"
	.string "GURU: Hm? Ein {STR_VAR_2} fangen?\n"
	.string "Nun, zunächst sind Geduld und Ausdauer\l"
	.string "gefragt. Das ist das Wichtigste.\p"
	.string "Sehen Sie {STR_VAR_1} dort drüben?\n"
	.string "Dieser TRAINER ist ein gutes Beispiel.\p"
	.string "Der TRAINER hat bereits {STR_VAR_3}\n"
	.string "POKéMON entkommen lassen.\p"
	.string "Aber {STR_VAR_1} wartet ab. Gibt nicht auf.\n"
	.string "Das ist die erste Regel beim Angeln von\l"
	.string "{STR_VAR_2}.\p"
	.string "MODERATOR: Ich verstehe…\p"
	.string "Oh! {STR_VAR_1} hat endlich das extrem\n"
	.string "schnelle {STR_VAR_2} gefangen!\p"
	.string "Der TRAINER ist den Tränen nahe vor\n"
	.string "Freude!\p"
	.string "Wenn ich diesen begeisterten Ausdruck\n"
	.string "sehe, möchte ich auch Angeln gehen.\p"
	.string "Zuschauer, warum nutzen Sie nicht die\n"
	.string "Chance, einige {STR_VAR_2} zu fischen?\p"
	.string "Bis zur nächsten Sendung leben Sie wohl\n"
	.string "und Petri heil!$"
	.endif
	.endif

gTVPokemonAnglerText01::
	.ifdef ENGLISH
	.string "{STR_VAR_2} ANGLER\p"
	.string "ANNOUNCER: Hello! Today, we'll get tips\n"
	.string "on fishing for {STR_VAR_2}.\p"
	.string "GURU, what advice can you give for\n"
	.string "catching {STR_VAR_2}?\p"
	.string "GURU: Hm? Catching {STR_VAR_2}?\n"
	.string "Well, let me tell you, use your fishing\l"
	.string "ROD with vigor!\p"
	.string "Do you see {STR_VAR_1} over there?\n"
	.string "See how the ROD is handled?\p"
	.string "That TRAINER's already caught\n"
	.string "{STR_VAR_3} in a row.\p"
	.string "ANNOUNCER: It's incredible!\n"
	.string "It looks like a storm…\p"
	.string "Seeing technique of that caliber, I'm\n"
	.string "getting the itch to go fishing, too.\p"
	.string "Viewers, why not take this as a cue to\n"
	.string "try some {STR_VAR_2} fishing?\p"
	.string "Until our next broadcast, farewell and\n"
	.string "good fishing to you all!$"
	.else
	.ifdef GERMAN
	.string " {STR_VAR_2}-ANGLER\p"
	.string "MODERATOR: Hallo! Heute gibt es\n"
	.string "Tipps zum Angeln von {STR_VAR_2}.\p"
	.string "GURU, welchen Ratschlag haben\n"
	.string "Sie für uns?\p"
	.string "GURU: Hm? {STR_VAR_2} fangen?\n"
	.string "Nun, setzen Sie Ihre ANGEL mit viel\l"
	.string "Kraft ein.\p"
	.string "Sehen Sie {STR_VAR_1} dort drüben?\n"
	.string "Wie hier die ANGEL gehandhabt wird?\p"
	.string "Der TRAINER hat bereits {STR_VAR_3}\n"
	.string "fangen können.\p"
	.string "MODERATOR: Das ist unglaublich!\n"
	.string "Es wirkt wie ein Sturm…\p"
	.string "Wenn ich solche Techniken beobachte,\n"
	.string "möchte ich auch sofort Angeln gehen.\p"
	.string "Zuschauer, warum nutzen Sie nicht die\n"
	.string "Chance, einige {STR_VAR_2} zu fischen?\p"
	.string "Bis zur nächsten Sendung leben Sie wohl\n"
	.string "und Petri heil!$"
	.endif
	.endif

gTVPokemonTodayFailedText00::
	.ifdef ENGLISH
	.string "Hello!\p"
	.string "It's time for POKéMON TODAY!\p"
	.string "BIG SIS: Hi! Is everyone peachy and\n"
	.string "perky today?\p"
	.string "Today, we're going to look at {STR_VAR_1}'s\n"
	.string "POKéMON {STR_VAR_2}!\p"
	.string "BIG BRO: Yeah! That's what we're going\n"
	.string "to do!$"
	.else
	.ifdef GERMAN
	.string "Hallo!\p"
	.string "Willkommen bei POKéMON HEUTE!\p"
	.string "SCHWESTER: Hallo! Alles gesund\n"
	.string "und munter?\p"
	.string "Heute werfen wir einen Blick auf das\n"
	.string "POKéMON {STR_VAR_2} von {STR_VAR_1}!\p"
	.string "BRUDER: Yeah! Genau das werden wir tun!$"
	.endif
	.endif

gTVPokemonTodayFailedText01::
	.ifdef ENGLISH
	.string "Oh!\n"
	.string "Speaking of {STR_VAR_1}…\p"
	.string "BIG SIS, I saw the TRAINER with my very\n"
	.string "own eyes!\p"
	.string "BIG SIS: Oh, what did you see?\p"
	.string "BIG BRO: Well, I had to go on a trip to\n"
	.string "{STR_VAR_2}.\p"
	.string "That's when I happened to come across\n"
	.string "{STR_VAR_1}, who was trying to catch the\l"
	.string "POKéMON {STR_VAR_3}, but…$"
	.else
	.ifdef GERMAN
	.string "Oh!\n"
	.string "Da wir gerade über {STR_VAR_1} sprechen…\p"
	.string "SCHWESTER, ich habe den TRAINER mit\n"
	.string "eigenen Augen gesehen!\p"
	.string "SCHWESTER: Und was hast du\n"
	.string "beobachtet?\p"
	.string "BRUDER: Nun, ich war gerade unterwegs\n"
	.string "nach {STR_VAR_2}.\p"
	.string "Da sah ich, wie {STR_VAR_1} versuchte, das \n"
	.string "POKéMON {STR_VAR_3} zu fangen, aber…$"
	.endif
	.endif

gTVPokemonTodayFailedText02::
	.ifdef ENGLISH
	.string "The POKéMON managed to get away!\p"
	.string "It ended up wasting this many\n"
	.string "POKé BALLS: {STR_VAR_2}!\p"
	.string "You should have seen the expression\n"
	.string "of frustration on {STR_VAR_1}'s face when\l"
	.string "the POKéMON took off!$"
	.else
	.ifdef GERMAN
	.string "Das POKéMON konnte flüchten!\p"
	.string "Und wie viele POKéBÄLLe wurden am Ende\n"
	.string "verbraucht? {STR_VAR_2}! Und das für nichts!\p"
	.string "Du hättest den frustrierten Ausdruck\n"
	.string "im Gesicht von {STR_VAR_1} sehen\p"
	.string "sollen, als das POKéMON sich aus dem\n"
	.string "Staub machte!$"
	.endif
	.endif

gTVPokemonTodayFailedText03::
	.ifdef ENGLISH
	.string "But {STR_VAR_1} goofed and made the\n"
	.string "POKéMON faint!\p"
	.string "It ended up wasting this many\n"
	.string "POKé BALLS: {STR_VAR_2}!\p"
	.string "You should have seen the expression\n"
	.string "of stunned dismay on {STR_VAR_1}'s face\l"
	.string "when the POKéMON fainted!$"
	.else
	.ifdef GERMAN
	.string "Aber {STR_VAR_1} hat so lange daneben-\n"
	.string "geworfen, bis das POKéMON\l"
	.string "kampfunfähig wurde!\p"
	.string "Und wie viele POKéBÄLLe wurden am Ende\n"
	.string "verbraucht? {STR_VAR_2}! Und das für nichts!\p"
	.string "Du hättest den Ausdruck fassungsloser\n"
	.string "Bestürzung auf dem Gesicht von\l"
	.string "{STR_VAR_1}\p"
	.string "sehen sollen, als das POKéMON plötzlich\n"
	.string "kampfunfähig wurde!$"
	.endif
	.endif

gTVPokemonTodayFailedText04::
	.ifdef ENGLISH
	.string "BIG SIS: Hey, there!\n"
	.string "That's not nice!\p"
	.string "You shouldn't be laughing at other\n"
	.string "people's misfortune!\p"
	.string "Oh, poor {STR_VAR_1}.\n"
	.string "What a shame!\p"
	.string "BIG BRO: That's true!\n"
	.string "Sorry for laughing.$"
	.else
	.ifdef GERMAN
	.string "SCHWESTER: Hey, du da!\n"
	.string "Das ist aber nicht nett!\p"
	.string "Du solltest dich nicht über das Unglück\n"
	.string "anderer lustig machen!\p"
	.string "Oh, mir tut {STR_VAR_1} Leid.\n"
	.string "Was für eine Schande!\p"
	.string "BRUDER: Da hast du Recht!\n"
	.string "Tut mir Leid, dass ich gelacht habe.$"
	.endif
	.endif

gTVPokemonTodayFailedText05::
	.ifdef ENGLISH
	.string "BIG SIS: Bufufu…\p"
	.string "BIG BRO: Hey!\n"
	.string "You just laughed, too!\p"
	.string "BIG SIS: Huh?!\p"
	.string "I didn't laugh!\n"
	.string "Honestly, I didn't!\p"
	.string "Oh, poor {STR_VAR_1}.\n"
	.string "What a shame!\p"
	.string "BIG BRO: …$"
	.else
	.ifdef GERMAN
	.string "SCHWESTER: Räusper Haha Räusper Haha…\p"
	.string "BRUDER: HEY!\n"
	.string "Du lachst ja!\p"
	.string "SCHWESTER: Ich???\p"
	.string "Ich habe doch nicht gelacht!\n"
	.string "Ehrlich nicht!\p"
	.string "Mir tut {STR_VAR_1} echt Leid.\n"
	.string "Was für eine Schande!\p"
	.string "BRUDER: …$"
	.endif
	.endif

gTVPokemonTodayFailedText06::
	.ifdef ENGLISH
	.string "BIG SIS: That's enough silliness!\n"
	.string "Let's look at today's POKéMON…\p"
	.string "Huh?\n"
	.string "We're out of time already?\p"
	.string "Aww!\n"
	.string "We couldn't profile a POKéMON today!\p"
	.string "BIG BRO: See you again next time!\p"
	.string "BIG SIS: Hey, don't end the show\n"
	.string "without me!$"
	.else
	.ifdef GERMAN
	.string "SCHWESTER: Schluss jetzt mit dem\n"
	.string "Blödsinn! Lasst uns das heutige\l"
	.string "POKéMON betrachten…\p"
	.string "Wie?\n"
	.string "Wir haben keine Zeit mehr dafür?\p"
	.string "Oooh! Dann haben wir heute ja gar kein\n"
	.string "POKéMON vorgestellt!\p"
	.string "BRUDER: Also, bis zum nächsten Mal!\p"
	.string "SCHWESTER: Hey, du kannst die Show\n"
	.string "doch nicht einfach ohne mich beenden!$"
	.endif
	.endif

gTVPokemonTodaySuccessfulText00::
	.ifdef ENGLISH
	.string "Hello!\p"
	.string "It's time for POKéMON TODAY!\p"
	.string "BIG SIS: Hi! Is everyone peachy and\n"
	.string "perky today?\p"
	.string "Today, we're going to look at {STR_VAR_1}'s\n"
	.string "POKéMON {STR_VAR_2}!\p"
	.string "BIG BRO: Yeah! That's what we're going\n"
	.string "to do!$"
	.else
	.ifdef GERMAN
	.string "Hallo!\p"
	.string "Willkommen bei POKéMON HEUTE!\p"
	.string "SCHWESTER: Hallo! Alles gesund\n"
	.string "und munter?\p"
	.string "Heute werfen wir einen Blick auf das\n"
	.string "POKéMON {STR_VAR_2} von {STR_VAR_1}!\p"
	.string "BRUDER: Yeah! Genau das werden wir tun!$"
	.endif
	.endif

gTVPokemonTodaySuccessfulText01::
	.ifdef ENGLISH
	.string "BIG SIS: {STR_VAR_1} gave the nickname\n"
	.string "{STR_VAR_3} to the {STR_VAR_2}!\p"
	.string "It sounds like {STR_VAR_3} is getting\n"
	.string "good, loving care!$"
	.else
	.ifdef GERMAN
	.string "SCHWESTER: {STR_VAR_1} hat {STR_VAR_2} den\n"
	.string "Kosenamen {STR_VAR_3} gegeben!\p"
	.string "{STR_VAR_3} scheint wirklich liebevoll\n"
	.string "behandelt zu werden.$"
	.endif
	.endif

gTVPokemonTodaySuccessfulText02::
	.ifdef ENGLISH
	.string "BIG BRO: The TRAINER had to throw this\n"
	.string "many POKé BALLS to catch it: {STR_VAR_3}!\p"
	.string "It finally took a single {STR_VAR_2}\n"
	.string "to catch it!$"
	.else
	.ifdef GERMAN
	.string "BRUDER: Und wie viele BÄLLe musste der\n"
	.string "TRAINER werfen, um es zu fangen? {STR_VAR_3}!\p"
	.string "Ein {STR_VAR_2} brachte den\n"
	.string "gewünschten Erfolg!$"
	.endif
	.endif

gTVPokemonTodaySuccessfulText03::
	.ifdef ENGLISH
	.string "BIG SIS: If it was that easy to catch,\n"
	.string "it must have been destiny that brought\l"
	.string "{STR_VAR_1} and the {STR_VAR_2} together!$"
	.else
	.ifdef GERMAN
	.string "SCHWESTER: Wenn das Fangen so einfach\n"
	.string "war, wollte das Schicksal {STR_VAR_1} und\l"
	.string "{STR_VAR_2} wohl zusammenführen!$"
	.endif
	.endif

gTVPokemonTodaySuccessfulText04::
	.ifdef ENGLISH
	.string "BIG SIS: Wow! That's so neat!\p"
	.string "But you know what they say, a POKéMON\n"
	.string "that takes a lot of effort to catch\l"
	.string "earns the love of its TRAINER!$"
	.else
	.ifdef GERMAN
	.string "SCHWESTER: Wow! Wie aufregend!\p"
	.string "Man sagt, dass ein POKéMON, das schwer\n"
	.string "zu fangen ist, die Liebe seines\l"
	.string "TRAINERs verdient!$"
	.endif
	.endif

gTVPokemonTodaySuccessfulText05::
	.ifdef ENGLISH
	.string "BIG SIS: {STR_VAR_1}'s {STR_VAR_2} is a\n"
	.string "memorable POKéMON because it took an\l"
	.string "invaluable MASTER BALL to catch!\p"
	.string "BIG BRO: Wow! That's mega-awesome!\p"
	.string "BIG SIS: {STR_VAR_1} must have really\n"
	.string "wanted that {STR_VAR_2}, for sure!$"
	.else
	.ifdef GERMAN
	.string "SCHWESTER: {STR_VAR_2} von {STR_VAR_1} ist\n"
	.string "ein bemerkenswertes POKéMON, da\p"
	.string "es nur mit dem unfehlbaren\n"
	.string "MEISTERBALL gefangen werden konnte!\p"
	.string "BRUDER: Wow! Das ist\n"
	.string "mega-beeindruckend!\p"
	.string "SCHWESTER: {STR_VAR_1} muss {STR_VAR_2} \n"
	.string "wirklich gewollt haben! Mit Sicherheit!$"
	.endif
	.endif

gTVPokemonTodaySuccessfulText06::
	.ifdef ENGLISH
	.string "BIG BRO: Then to give the nickname\n"
	.string "{STR_VAR_3} to that {STR_VAR_2}…\p"
	.string "You really get a good idea about\n"
	.string "{STR_VAR_1}'s TRAINER sense.\p"
	.string "BIG SIS: I second that notion!$"
	.else
	.ifdef GERMAN
	.string "BRUDER: Und dann erhält {STR_VAR_2}\n"
	.string "auch noch den Kosenamen {STR_VAR_3}…\p"
	.string "Das ermöglicht einen guten Einblick in\n"
	.string "die Einstellung von TRAINER {STR_VAR_1}.\p"
	.string "SCHWESTER: Das sehe ich auch so!$"
	.endif
	.endif

gTVPokemonTodaySuccessfulText07::
	.ifdef ENGLISH
	.string "If it were me, I'd give that nickname\n"
	.string "to something like this {STR_VAR_3}!\p"
	.string "BIG BRO: Whoa! That could be the start\n"
	.string "of something new!$"
	.else
	.ifdef GERMAN
	.string "Ich würde diesen Kosenamen einem\n"
	.string "{STR_VAR_3} geben!\p"
	.string "BRUDER: Hui! Das wäre der Anfang von\n"
	.string "etwas ganz Neuem.$"
	.endif
	.endif

gTVPokemonTodaySuccessfulText08::
	.ifdef ENGLISH
	.string "{STR_VAR_2} the {STR_VAR_1}?\n"
	.string "Doesn't that sound perfect?\p"
	.string "The letters and everything--they\n"
	.string "sound just right for the POKéMON\l"
	.string "{STR_VAR_1}!\p"
	.string "BIG BRO: Yeah, true, that!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}, das {STR_VAR_1}?\n"
	.string "Hört sich das nicht einfach perfekt an?\p"
	.string "Die Buchstaben und alles - wie\n"
	.string "geschaffen für das POKéMON\l"
	.string "{STR_VAR_1}!\p"
	.string "BRUDER: Yeah! Stimmt! Absolut!$"
	.endif
	.endif

gTVPokemonTodaySuccessfulText09::
	.ifdef ENGLISH
	.string "As far as I know, no TRAINER has ever\n"
	.string "given the nickname {STR_VAR_2} to their\l"
	.string "{STR_VAR_1}!\p"
	.string "BIG BRO: That just goes to show what\n"
	.string "great taste the TRAINER has in picking\l"
	.string "nicknames!$"
	.else
	.ifdef GERMAN
	.string "Soweit ich weiß, hat noch kein TRAINER\n"
	.string "jemals seinem {STR_VAR_1} den\l"
	.string "Kosenamen {STR_VAR_2} gegeben!\p"
	.string "BRUDER: Das zeigt doch nur, welch einen\n"
	.string "hervorragenden Geschmack der TRAINER\l"
	.string "bei der Wahl des Kosenamens bewies!$"
	.endif
	.endif

gTVPokemonTodaySuccessfulText10::
	.ifdef ENGLISH
	.string "The next time I catch a POKéMON,\n"
	.string "I should give it the name {STR_VAR_2}.\p"
	.string "BIG BRO: Huh? Me, too!\n"
	.string "I'll use the nickname {STR_VAR_2}, too!$"
	.else
	.ifdef GERMAN
	.string "Mein nächstes POKéMON bekommt den\n"
	.string "Kosenamen {STR_VAR_2}.\p"
	.string "BRUDER: Wie? Meines auch!\n"
	.string "Ich werde es auch {STR_VAR_2} nennen!$"
	.endif
	.endif

gTVPokemonTodaySuccessfulText11::
	.ifdef ENGLISH
	.string "BIG SIS: Oh, no!\n"
	.string "Look at the time!\p"
	.string "Well, gang, this is it for today.\n"
	.string "See you again next time!\p"
	.string "BIG BRO: Remember, it could be your\n"
	.string "POKéMON in the spotlight next time!$"
	.else
	.ifdef GERMAN
	.string "SCHWESTER: Oh je!\n"
	.string "Schau dir nur die Uhrzeit an!\p"
	.string "Nun, Freunde, das war es für heute.\n"
	.string "Wir sehen uns das nächste Mal wieder!\p"
	.string "BRUDER: Denkt daran, es könnte euer\n"
	.string "POKéMON sein, das wir hier vorstellen!$"
	.endif
	.endif

SmartShopper_Text_Intro::
	.ifdef ENGLISH
	.string "Hello!\p"
	.string "It's time for TODAY'S SMART SHOPPER.\p"
	.string "INTERVIEWER: How are you, viewers?\p"
	.string "Today we're visiting a shop\n"
	.string "in {STR_VAR_2}.\p"
	.string "Let's check on what the hot sellers\n"
	.string "have been recently.$"
	.else
	.ifdef GERMAN
	.string "Hallo!\p"
	.string "Zeit für den heutigen CLEVERKAUF!\p"
	.string "INTERVIEWER: Wie geht es euch?\p"
	.string "Heute besuchen wir ein Geschäft\n"
	.string "in {STR_VAR_2}.\p"
	.string "Schauen wir doch mal, welche Artikel\n"
	.string "dort besonders begehrt sind.$"
	.endif
	.endif

SmartShopper_Text_ClerkNormal::
	.ifdef ENGLISH
	.string "Let's interview the clerk to get the\n"
	.string "lowdown.\p"
	.string "Hi, how's your business?\p"
	.string "CLERK: Oh, we're doing excellent.\p"
	.string "Recently, {STR_VAR_2} has been\n"
	.string "selling especially strongly.\p"
	.string "Why, just the other day a TRAINER\n"
	.string "named {STR_VAR_1} bought {STR_VAR_3}.$"
	.else
	.ifdef GERMAN
	.string "Fragen wir doch einfach den Verkäufer\n"
	.string "hier.\p"
	.string "Hallo, wie läuft das Geschäft?\p"
	.string "VERKÄUFER: Oh, ausgezeichnet!\p"
	.string "Im Moment verkaufen wir {STR_VAR_2}\n"
	.string "besonders gut.\p"
	.string "Und gerade hat ein TRAINER namens\n"
	.string "{STR_VAR_1} {STR_VAR_3} gekauft.$"
	.endif
	.endif

SmartShopper_Text_RandomComment1::
	.ifdef ENGLISH
	.string "INTERVIEWER: The TRAINER bought\n"
	.string "{STR_VAR_3} {STR_VAR_2}S? That's a haul!\p"
	.string "If I may say so, {STR_VAR_1} must have\n"
	.string "been stocking up for a long journey\l"
	.string "to far-off places.\p"
	.string "For traveling, {STR_VAR_2}S are so\n"
	.string "important!$"
	.else
	.ifdef GERMAN
	.string "INTERVIEWER: Der TRAINER hat {STR_VAR_3}-mal\n"
	.string "{STR_VAR_2} gekauft? Wow!\p"
	.string "Mir scheint es, als ob {STR_VAR_1} sich\n"
	.string "für eine längere Reise rüstet.\p"
	.string "Auf Reisen ist {STR_VAR_2} einfach\n"
	.string "unverzichtbar.$"
	.endif
	.endif

SmartShopper_Text_RandomComment2::
	.ifdef ENGLISH
	.string "INTERVIEWER: Speaking of the item\n"
	.string "{STR_VAR_2}, I just bought {STR_VAR_3} of\l"
	.string "them recently.\p"
	.string "After all, {STR_VAR_2}'s a great item!$"
	.else
	.ifdef GERMAN
	.string "INTERVIEWER: Da wir gerade von\n"
	.string "{STR_VAR_2} sprechen…\l"
	.string "Ich habe {STR_VAR_3} gekauft.\p"
	.string "{STR_VAR_2} ist ein großartiges Item!$"
	.endif
	.endif

SmartShopper_Text_RandomComment3::
	.ifdef ENGLISH
	.string "INTERVIEWER: {STR_VAR_2}?!\n"
	.string "But {STR_VAR_3} of them?!\p"
	.string "I didn't think there would be anyone\n"
	.string "buying that many.\p"
	.string "My goodness, I can only afford one or\n"
	.string "two at a time…$"
	.else
	.ifdef GERMAN
	.string "INTERVIEWER: {STR_VAR_2}?!?\n"
	.string "Und gleich {STR_VAR_3} davon?!?\p"
	.string "Ich hätte nicht gedacht, dass jemand\n"
	.string "so viel davon kauft.\p"
	.string "Meine Güte, ich könnte mir höchstens\n"
	.string "ein oder zwei auf einmal davon leisten…$"
	.endif
	.endif

SmartShopper_Text_RandomComment4::
	.ifdef ENGLISH
	.string "INTERVIEWER: One time, I bought\n"
	.string "a whole lot of the item {STR_VAR_2}.\p"
	.string "But it turned out to be too many.\n"
	.string "I ended up regretting it…\p"
	.string "Since then, I only buy strictly what\n"
	.string "I absolutely need…\p"
	.string "Oops!\p"
	.string "There's no point talking about me!$"
	.else
	.ifdef GERMAN
	.string "INTERVIEWER: Ich habe erst ein Mal\n"
	.string "sehr viel gekauft. Eine große\l"
	.string "Stückzahl des Items {STR_VAR_2}.\p"
	.string "Aber schließlich war auch das zu viel.\n"
	.string "Ich habe es hinterher echt bereut…\p"
	.string "Seitdem kaufe ich grundsätzlich nur\n"
	.string "noch das, was ich wirklich brauche…\p"
	.string "Huups!\p"
	.string "Wir wollen doch hier nicht über mich\n"
	.string "reden!$"
	.endif
	.endif

SmartShopper_Text_SecondItem::
	.ifdef ENGLISH
	.string "CLERK: {STR_VAR_1} also bought the item\n"
	.string "{STR_VAR_2} in bulk, taking {STR_VAR_3}.\p"
	.string "INTERVIEWER: Oh, that's smart.\n"
	.string "{STR_VAR_2}'s a very good item, too.$"
	.else
	.ifdef GERMAN
	.string "VERKÄUFER: {STR_VAR_1} hat auch von dem\n"
	.string "Item {STR_VAR_2} gleich {STR_VAR_3}\l"
	.string "Exemplare gekauft.\p"
	.string "INTERVIEWER: Oh, das ist clever.\n"
	.string "{STR_VAR_2} ist ein sehr gutes Item…$"
	.endif
	.endif

SmartShopper_Text_ThirdItem::
	.ifdef ENGLISH
	.string "CLERK: And, the TRAINER also bought\n"
	.string "{STR_VAR_3} of the item {STR_VAR_2}.$"
	.else
	.ifdef GERMAN
	.string "VERKÄUFER: Und der TRAINER kaufte\n"
	.string "von dem Item {STR_VAR_2} {STR_VAR_3}\l"
	.string "Exemplare.$"
	.endif
	.endif

SmartShopper_Text_DuringSale::
	.ifdef ENGLISH
	.string "CLERK: Plus, it was during a big sale.\n"
	.string "That's smart shopping.$"
	.else
	.ifdef GERMAN
	.string "VERKÄUFER: Und zwar als es im Sonder-\n"
	.string "angebot war. Clever!!!$"
	.endif
	.endif

SmartShopper_Text_OutroNormal::
	.ifdef ENGLISH
	.string "INTERVIEWER: Hmm… {STR_VAR_1} sounds like\n"
	.string "quite the shrewd bargain hunter!\p"
	.string "In total, {STR_VAR_1}'s purchases came to…\p"
	.string "¥{STR_VAR_2}?!\n"
	.string "What an amazing sum!\p"
	.string "Oops! We're out of time!\n"
	.string "See you on our next broadcast!$"
	.else
	.ifdef GERMAN
	.string "INTERVIEWER: Hmm… {STR_VAR_1} scheint ein\n"
	.string "richtiger Schnäppchenjäger zu sein!\p"
	.string "{STR_VAR_1} brauchte also für alles nur…\p"
	.string "¥{STR_VAR_2} zu bezahlen?!?\n"
	.string "Wie unglaublich günstig!\p"
	.string "Oh! Wir sind am Ende unserer Sendung!\n"
	.string "Bis zum nächsten Mal! Auf Wiedersehen!$"
	.endif
	.endif

SmartShopper_Text_IsVIP::
	.ifdef ENGLISH
	.string "CLERK: {STR_VAR_1} is a VIP customer,\n"
	.string "no doubt about it.$"
	.else
	.ifdef GERMAN
	.string "VERKÄUFER: {STR_VAR_1} ist ein VIP-Kunde,\n"
	.string "daran besteht kein Zweifel.$"
	.endif
	.endif

SmartShopper_Text_ClerkMax::
	.ifdef ENGLISH
	.string "Let's interview the clerk to get the\n"
	.string "lowdown.\p"
	.string "Hi, how's your business?\p"
	.string "CLERK: Oh, we're doing unbelievable\n"
	.string "business. It's almost overwhelming.\p"
	.string "Recently, a TRAINER named {STR_VAR_1}\n"
	.string "bought the item {STR_VAR_2} in bulk.\p"
	.string "The TRAINER almost cleared out our\n"
	.string "entire stock of {STR_VAR_2}S.\p"
	.string "I never dreamt that any customer\n"
	.string "would ever need so many {STR_VAR_2}S.\l"
	.string "It's just unheard of!\p"
	.string "INTERVIEWER: So that would be like 100\n"
	.string "or 200 sold?\p"
	.string "CLERK: Oh, no, much more than that!\p"
	.string "INTERVIEWER: Oh, my goodness!\n"
	.string "{STR_VAR_1} must be a special shopper!\p"
	.string "CLERK: {STR_VAR_1} is a VIP customer,\n"
	.string "no doubt about it.$"
	.else
	.ifdef GERMAN
	.string "Fragen wir doch mal den Verkäufer.\p"
	.string "Hallo, wie läuft das Geschäft?\p"
	.string "VERKÄUFER: Oh, es ist einfach un-\n"
	.string "glaublich. Einfach überwältigend.\p"
	.string "Vor kurzem hat ein TRAINER namens\n"
	.string "{STR_VAR_1} das Item {STR_VAR_2}\l"
	.string "in großer Stückzahl gekauft.\p"
	.string "Er hat fast das ganze Regal mit\n"
	.string "{STR_VAR_2} leergeräumt.\p"
	.string "Ich hätte nie gedacht, dass es einen\n"
	.string "TRAINER gibt, der {STR_VAR_2} \l"
	.string "in so großen Mengen benötigt!\p"
	.string "INTERVIEWER: Das waren dann ja 100\n"
	.string "oder 200 Exemplare!?!\p"
	.string "VERKÄUFER: Oh, nein. Viel, viel mehr!\p"
	.string "INTERVIEWER: Du meine Güte! {STR_VAR_1}\n"
	.string "muss ein ganz besonderer Kunde sein!\p"
	.string "VERKÄUFER: {STR_VAR_1} ist ein VIP-Kunde,\n"
	.string "daran besteht gar kein Zweifel!$"
	.endif
	.endif

SmartShopper_Text_OutroMax::
	.ifdef ENGLISH
	.string "INTERVIEWER: Hmm…\n"
	.string "That is amazing.\p"
	.string "But why would the TRAINER need to buy\n"
	.string "so many?\p"
	.string "… …\p"
	.string "The mystery deepens, but this is all\n"
	.string "the time we have today.\l"
	.string "See you on our next broadcast!\p"
	.string "Still, {STR_VAR_1} is certainly an enigma…$"
	.else
	.ifdef GERMAN
	.string "INTERVIEWER: Hmm…\n"
	.string "Das ist unglaublich.\p"
	.string "Aber warum hat der TRAINER wohl gleich\n"
	.string "so viel auf einmal gekauft?\p"
	.string "… …\p"
	.string "Ein Mysterium… Aber leider haben wir\n"
	.string "keine Zeit mehr, hinter das Geheimnis\l"
	.string "zu kommen. Bis zur nächsten Sendung!\p"
	.string "{STR_VAR_1} muss ein Rätsel bleiben…$"
	.endif
	.endif

gTVWorldOfMastersText00::
	.ifdef ENGLISH
	.string "THE WORLD OF MASTERS\p"
	.string "Hello, viewers.\p"
	.string "Perhaps you are aware of a TRAINER\n"
	.string "named {STR_VAR_1}.\p"
	.string "{STR_VAR_1} is famous as a master at\n"
	.string "catching POKéMON.\p"
	.string "{STR_VAR_1}'s quest for POKéMON depends\n"
	.string "entirely on a careful search on foot.\p"
	.string "On one memorable day, the TRAINER\n"
	.string "walked some {STR_VAR_2} steps.\p"
	.string "The total number of POKéMON caught\n"
	.string "that day reached an impressive {STR_VAR_3}!$"
	.else
	.ifdef GERMAN
	.string "DIE WELT DER MEISTER\p"
	.string "Hallo, liebe Zuschauer.\p"
	.string "Vielleicht ist Ihnen schon einmal der\n"
	.string "TRAINER {STR_VAR_1} begegnet.\p"
	.string "{STR_VAR_1} ist berühmt als Meister im\n"
	.string "Fangen von POKéMON.\p"
	.string "Der Erfolg von {STR_VAR_1} im Fangen von\n"
	.string "POKéMON basiert auf einer gründlichen\l"
	.string "Suche, die zu Fuß stattfindet.\p"
	.string "Eines denkwürdigen Tages machte\n"
	.string "der TRAINER  {STR_VAR_2} Schritte.\p"
	.string "Die Gesamtzahl der an diesem Tag\n"
	.string "gefangenen POKéMON betrug {STR_VAR_3}!$"
	.endif
	.endif

gTVWorldOfMastersText01::
	.ifdef ENGLISH
	.string "That remarkable feat must have been\n"
	.string "possible because of the trust between\l"
	.string "the TRAINER and {STR_VAR_1}.$"
	.else
	.ifdef GERMAN
	.string "Diese bemerkenswerte Leistung war nur\n"
	.string "möglich, weil zwischen dem TRAINER und\l"
	.string "{STR_VAR_1} tiefes Vertrauen besteht.$"
	.endif
	.endif

gTVWorldOfMastersText02::
	.ifdef ENGLISH
	.string "The master caught the day's last\n"
	.string "{STR_VAR_3} near {STR_VAR_2}.\p"
	.string "That POKéMON apparently enjoys\n"
	.string "a special status as a record holder.\p"
	.string "Skilled TRAINERS should be encouraged\n"
	.string "to challenge this fine record.\p"
	.string "That's all for today.\n"
	.string "Please tune in next time.$"
	.else
	.ifdef GERMAN
	.string "Der Meister hat das letzte {STR_VAR_3}\n"
	.string "an diesem Tage in der Nähe von\l"
	.string "{STR_VAR_2} gefangen.\p"
	.string "Dieses POKéMON kann sich nun an\n"
	.string "dem besonderen Rang des Rekordhalters\l"
	.string "erfreuen.\p"
	.string "Talentierte TRAINER sollten versuchen,\n"
	.string "diesen Rekord zu brechen.\p"
	.string "Das war’s für heute.\n"
	.string "Bis zum nächsten Mal.$"
	.endif
	.endif

gTVTodaysRivalTrainerText00::
	.ifdef ENGLISH
	.string "TODAY'S RIVAL TRAINER!\p"
	.string "Hello, fellow POKéMON TRAINERS!\n"
	.string "How are we all doing today?\p"
	.string "Today, like every other day,\n"
	.string "we'll examine one of our rivals!$"
	.else
	.ifdef GERMAN
	.string "HEUTIGER RIVALE!\p"
	.string "Hallo, geschätzte TRAINER!\n"
	.string "Wie geht es euch heute?\p"
	.string "Heute wollen wir, wie an jedem Tag,\n"
	.string "einen Blick auf unsere Rivalen werfen.$"
	.endif
	.endif

gTVTodaysRivalTrainerText07::
	.ifdef ENGLISH
	.string "Today's rival TRAINER is {STR_VAR_1},\n"
	.string "who's around {STR_VAR_3} now.\p"
	.string "{STR_VAR_1} has so far registered\n"
	.string "{STR_VAR_2} POKéMON in the POKéDEX.$"
	.else
	.ifdef GERMAN
	.string "Unser heutiger Rivale ist\n"
	.string "TRAINER {STR_VAR_1}. Er befindet sich\p"
	.string "momentan in der Gegend\n"
	.string "von {STR_VAR_3}.\p"
	.string "{STR_VAR_1} hat bis jetzt {STR_VAR_2} POKéMON\n"
	.string "im POKéDEX verzeichnet.$"
	.endif
	.endif

gTVTodaysRivalTrainerText08::
	.ifdef ENGLISH
	.string "Today's rival TRAINER is {STR_VAR_1},\n"
	.string "who's in a SECRET BASE now.\p"
	.string "{STR_VAR_1} has so far registered\n"
	.string "{STR_VAR_2} POKéMON in the POKéDEX.$"
	.else
	.ifdef GERMAN
	.string "Unser heutiger Rivale ist\n"
	.string "TRAINER {STR_VAR_1}. Er befindet sich\l"
	.string "momentan in einer GEHEIMBASIS.\p"
	.string "{STR_VAR_1} hat bis jetzt {STR_VAR_2} POKéMON\n"
	.string "im POKéDEX verzeichnet.$"
	.endif
	.endif

gTVTodaysRivalTrainerText09::
	.ifdef ENGLISH
	.string "Today's rival TRAINER is {STR_VAR_1}.\p"
	.string "So far, {STR_VAR_1} has registered\n"
	.string "{STR_VAR_2} POKéMON in the POKéDEX.$"
	.else
	.ifdef GERMAN
	.string "Unser heutiger Rivale ist\n"
	.string "TRAINER {STR_VAR_1}. \p"
	.string "{STR_VAR_1} hat bis jetzt {STR_VAR_2} POKéMON\n"
	.string "im POKéDEX verzeichnet.$"
	.endif
	.endif

gTVTodaysRivalTrainerText10::
	.ifdef ENGLISH
	.string "Today's rival TRAINER is {STR_VAR_1},\n"
	.string "who's on a ferry now.\p"
	.string "{STR_VAR_1} has so far registered\n"
	.string "{STR_VAR_2} POKéMON in the POKéDEX.$"
	.else
	.ifdef GERMAN
	.string "Unser heutiger Rivale ist\n"
	.string "TRAINER {STR_VAR_1}. Er befindet sich\l"
	.string "gerade auf einer Fähre.\p"
	.string "{STR_VAR_1} hat bis jetzt {STR_VAR_2} POKéMON\n"
	.string "im POKéDEX verzeichnet.$"
	.endif
	.endif

	.string "$"

gTVTodaysRivalTrainerText01::
	.ifdef ENGLISH
	.string "And how many BADGES does our rival\n"
	.string "have? The number is {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Und wie viele ORDEN besitzt euer\n"
	.string "Rivale bereits? {STR_VAR_1}!$"
	.endif
	.endif

gTVTodaysRivalTrainerText02::
	.ifdef ENGLISH
	.string "But our rival hasn't obtained\n"
	.string "a single BADGE yet!$"
	.else
	.ifdef GERMAN
	.string "Aber unser Rivale besitzt keinen\n"
	.string "einzigen ORDEN.$"
	.endif
	.endif

gTVTodaysRivalTrainerText03::
	.ifdef ENGLISH
	.string "Our rival hasn't obtained a single\n"
	.string "BATTLE FRONTIER Symbol yet.$"
	.else
	.ifdef GERMAN
	.string "Unser RIVALE hat bis jetzt noch kein\n"
	.string "einziges SYMBOL der KAMPFZONE\l"
	.string "erhalten.$"
	.endif
	.endif

gTVTodaysRivalTrainerText04::
	.ifdef ENGLISH
	.string "Let's see how many BATTLE FRONTIER\n"
	.string "Symbols our rival has.\p"
	.string "Gold Symbols: {STR_VAR_1}!\n"
	.string "Silver Symbols: {STR_VAR_2}!$"
	.else
	.ifdef GERMAN
	.string "Schauen wir uns mal an, wie viele\n"
	.string "SYMBOLE der KAMPFZONE unser\l"
	.string "Rivale bereits besitzt.\p"
	.string "Goldene SYMBOLE: {STR_VAR_1}!\n"
	.string "Silberne SYMBOLE: {STR_VAR_2}!$"
	.endif
	.endif

gTVTodaysRivalTrainerText05::
	.ifdef ENGLISH
	.string "Our rival has collected {STR_VAR_1} Battle\n"
	.string "Point(s) at the BATTLE FRONTIER.$"
	.else
	.ifdef GERMAN
	.string "Unser Rivale hat sich {STR_VAR_1} Gewinn-\n"
	.string "punkte in der KAMPFZONE erkämpft.$"
	.endif
	.endif

gTVTodaysRivalTrainerText06::
	.ifdef ENGLISH
	.string "So, how did you measure up in\n"
	.string "comparison to {STR_VAR_1}?\p"
	.string "The adventure rolls on!\p"
	.string "Fellow TRAINERS!\p"
	.string "Let's all keep moving forward\n"
	.string "and ahead of our rivals!$"
	.else
	.ifdef GERMAN
	.string "Und wie schneidest du im Vergleich zu\n"
	.string "{STR_VAR_1} ab?\p"
	.string "Das Abenteuer geht weiter!\p"
	.string "Liebe TRAINER!\p"
	.string "Lasst uns alle unseren Weg weitergehen\n"
	.string "und unsere Rivalen überrunden!$"
	.endif
	.endif

TrendWatcher_Text_Intro::
	.ifdef ENGLISH
	.string "DEWFORD TREND-WATCHER NETWORK!\p"
	.string "MC: Wassup?\n"
	.string "We'll keep it real with the latest on\l"
	.string "what's hip and happening in DEWFORD.\p"
	.string "Our guest today is this old cat whose\n"
	.string "claim to fame is being the authority\l"
	.string "on all things in DEWFORD.\p"
	.string "Old man: Glad to be here.\p"
	.string "MC: Let's cut to the chase, right on.\p"
	.string "What's your word on what's groovin'\n"
	.string "the good folks of DEWFORD?\p"
	.string "Old man: {STR_VAR_1} {STR_VAR_2}.\p"
	.string "MC: {STR_VAR_1} {STR_VAR_2},\n"
	.string "you say?\p"
	.string "Old man: No.\p"
	.string "{STR_VAR_1} {STR_VAR_2} never\n"
	.string "did get popular at all.\p"
	.string "Would you like to hear about it?\p"
	.string "MC: Uh, no. What we want to know is\n"
	.string "what's the in thing of the moment…$"
	.else
	.ifdef GERMAN
	.string "FAUSTAUHAVEN TREND-SHOW!\p"
	.string "MC: Wie geht’s?\n"
	.string "Wir bringen euch das pralle Leben ins\l"
	.string "Haus und zeigen euch, was in\p"
	.string "FAUSTAUHAVEN gerade angesagt ist.\n"
	.string "Unser heutiger Gast ist dieser alte\l"
	.string "Freund hier, der von sich behauptet,\p"
	.string "sich in FAUSTAUHAVEN in allem\n"
	.string "auszukennen.\p"
	.string "Alter Mann: Es freut mich, hier zu sein.\p"
	.string "MC: Kommen wir gleich zur Sache.\p"
	.string "Sag uns, was gerade angesagt ist in\n"
	.string "FAUSTAUHAVEN.\p"
	.string "Alter Mann: {STR_VAR_1}\n"
	.string "{STR_VAR_2}!\p"
	.string "MC: {STR_VAR_1} {STR_VAR_2}? \p"
	.string "Alter Mann: Nein.\p"
	.string "{STR_VAR_1} {STR_VAR_2} war bei den\n"
	.string "Leuten niemals so richtig angesagt.\p"
	.string "Möchtet ihr etwas darüber hören?\p"
	.string "MC: Äh, nein. Für uns zählt nur, was\n"
	.string "gerade jetzt im Trend liegt und\l"
	.string "angesagt ist…$"
	.endif
	.endif

@ Identical to below, may have been different in other languages
TrendWatcher_Text_MaleTaughtMePhrase::
	.ifdef ENGLISH
	.string "Old man: {STR_VAR_1} {STR_VAR_2}\n"
	.string "was what {STR_VAR_3} from LITTLEROOT\l"
	.string "taught me as being trendy…$"
	.else
	.ifdef GERMAN
	.string "Alter Mann: {STR_VAR_3} aus WURZELHEIM\n"
	.string "hat mir verraten, dass {STR_VAR_1}\l"
	.string "{STR_VAR_2} angesagt sei…$"
	.endif
	.endif

TrendWatcher_Text_FemaleTaughtMePhrase::
	.ifdef ENGLISH
	.string "Old man: {STR_VAR_1} {STR_VAR_2}\n"
	.string "was what {STR_VAR_3} from LITTLEROOT\l"
	.string "taught me as being trendy…$"
	.else
	.ifdef GERMAN
	.string "Alter Mann: {STR_VAR_3} aus WURZELHEIM\n"
	.string "hat mir verraten, dass {STR_VAR_1}\l"
	.string "{STR_VAR_2} angesagt sei…$"
	.endif
	.endif

TrendWatcher_Text_PhraseWasHopeless::
	.ifdef ENGLISH
	.string "But it was utterly hopeless.\p"
	.string "{STR_VAR_1} {STR_VAR_2} festival!\p"
	.string "{STR_VAR_1} {STR_VAR_2} contest!\p"
	.string "I tried teaching everyone the best\n"
	.string "I could, but…\p"
	.string "Perhaps the {STR_VAR_1} part just\n"
	.string "wasn't right…\p"
	.string "MC: Uh, excuse me, compadre, I need\n"
	.string "to hear about what's in now…$"
	.else
	.ifdef GERMAN
	.string "Aber es war aussichtslos:\p"
	.string "Ich organisierte {STR_VAR_1}\n"
	.string "{STR_VAR_2}-Festivals!\l"
	.string "Und auch Wettbewerbe!\p"
	.string "Ich versuchte, es jedem schmackhaft\n"
	.string "zu machen…\p"
	.string "Vielleicht passte {STR_VAR_1}\n"
	.string "einfach nicht…\p"
	.string "MC: Äh, Entschuldigung… Aber wir\n"
	.string "möchten wissen, was jetzt angesagt\l"
	.string "ist…$"
	.endif
	.endif

@ Identical to below, may have been different in other languages
TrendWatcher_Text_MaleTellMeBigger::
	.ifdef ENGLISH
	.string "Old man: {STR_VAR_3}!\n"
	.string "Please, tell me something bigger than\l"
	.string "that {STR_VAR_1} {STR_VAR_2}!$"
	.else
	.ifdef GERMAN
	.string "Alter Mann: {STR_VAR_3}!\n"
	.string "Komm mit etwas Besserem um die Ecke\l"
	.string "als {STR_VAR_1} {STR_VAR_2}!$"
	.endif
	.endif

TrendWatcher_Text_FemaleTellMeBigger::
	.ifdef ENGLISH
	.string "Old man: {STR_VAR_3}!\n"
	.string "Please, tell me something bigger than\l"
	.string "that {STR_VAR_1} {STR_VAR_2}!$"
	.else
	.ifdef GERMAN
	.string "Alter Mann: {STR_VAR_3}!\n"
	.string "Komm mit etwas Besserem um die Ecke\l"
	.string "als {STR_VAR_1} {STR_VAR_2}!$"
	.endif
	.endif

TrendWatcher_Text_Outro::
	.ifdef ENGLISH
	.string "MC: …Uh… So, there you have it,\n"
	.string "all you trendy, hep cats out there!\p"
	.string "{STR_VAR_1} {STR_VAR_2}…uh…\n"
	.string "Didn't get hip or happening in DEWFORD!\p"
	.string "My time is up. Catch you on the fly!\p"
	.string "Old man: {STR_VAR_1} {STR_VAR_2}!$"
	.else
	.ifdef GERMAN
	.string "MC: Äh… Ihr habt es gehört, Fans des\n"
	.string "neuesten Trends!\p"
	.string "{STR_VAR_1} {STR_VAR_2}… Äh…\n"
	.string "War in FAUSTAUHAVEN ein Reinfall.\p"
	.string "Unsere Zeit ist um! Macht’s gut!\p"
	.string "Alter Mann: {STR_VAR_1}\n"
	.string "{STR_VAR_2}!$"
	.endif
	.endif

gTVHoennTreasureInvestigatorsText00::
	.ifdef ENGLISH
	.string "HOENN TREASURE INVESTIGATORS!\p"
	.string "Hi, gang!\n"
	.string "Score any secret items lately?\p"
	.string "As always, we'll examine eyewitness\n"
	.string "reports of secrets from all over!\p"
	.string "Let's start with a letter.\n"
	.string "It says, “{STR_VAR_1} discovered!”$"
	.else
	.ifdef GERMAN
	.string "HOENN SCHATZSUCHER!\p"
	.string "Hallo, ihr Suchenden!\n"
	.string "Habt ihr in letzter Zeit verborgene\l"
	.string "Items entdeckt?\p"
	.string "Wie immer sind wir offen für\n"
	.string "Augenzeugen, die uns von den ver-\l"
	.string "borgenen Schätzen berichten.\p"
	.string "Hier haben wir einen Brief!\n"
	.string "Darin steht: “{STR_VAR_1} entdeckt!”$"
	.endif
	.endif

gTVHoennTreasureInvestigatorsText01::
	.ifdef ENGLISH
	.string "Wow, we'd better check this letter\n"
	.string "out! Let me read it to you.\p"
	.string "…Dear INVESTIGATORS,\n"
	.string "I hope you are well.\p"
	.string "I recently saw {STR_VAR_2} somewhere\n"
	.string "around {STR_VAR_3}.\p"
	.string "The TRAINER found the item\n"
	.string "{STR_VAR_1}. It made me envious.\p"
	.string "…Well, good going, {STR_VAR_2}!\p"
	.string "Viewers, let that motivate you to\n"
	.string "fire up your ITEMFINDERS and search!\p"
	.string "I'll be waiting for exciting news\n"
	.string "from all of you!$"
	.else
	.ifdef GERMAN
	.string "Wow! Den Brief muss ich euch vorlesen!\p"
	.string "Meine lieben SCHATZSUCHER, ich hoffe,\n"
	.string "es geht euch allen gut.\p"
	.string "Vor kurzem habe ich {STR_VAR_2} in der\n"
	.string "Nähe von {STR_VAR_3} getroffen.\p"
	.string "Dieser TRAINER hatte das Item\n"
	.string "{STR_VAR_1} gefunden.\p"
	.string "Ich war richtig neidisch!\p"
	.string "Gut gemacht, {STR_VAR_2}!\p"
	.string "Das sollte euch als Ansporn dienen!\n"
	.string "Powert eure DETEKTORen auf und macht\p"
	.string "euch auf die Suche! Ich warte auf\n"
	.string "interessante Berichte von euch allen!$"
	.endif
	.endif

gTVHoennTreasureInvestigatorsText02::
	.ifdef ENGLISH
	.string "Wow, we'd better check this letter\n"
	.string "out! Let me read it to you.\p"
	.string "…Dear INVESTIGATORS,\n"
	.string "I hope you are well.\p"
	.string "I recently saw {STR_VAR_2} on a ferry.\p"
	.string "The TRAINER found the item\n"
	.string "{STR_VAR_1}. It made me envious.\p"
	.string "…Well, good going, {STR_VAR_2}!\p"
	.string "Viewers, let that motivate you to\n"
	.string "fire up your ITEMFINDERS and search!\p"
	.string "I'll be waiting for exciting news\n"
	.string "from all of you!$"
	.else
	.ifdef GERMAN
	.string "Wow! Den Brief muss ich euch vorlesen!\p"
	.string "Meine lieben SCHATZSUCHER, ich hoffe,\n"
	.string "es geht euch allen gut.\p"
	.string "Vor kurzem habe ich {STR_VAR_2} auf\n"
	.string "einer Fähre getroffen.\p"
	.string "Dieser TRAINER hatte das Item\n"
	.string "{STR_VAR_1} gefunden.\p"
	.string "Ich war richtig neidisch!\p"
	.string "Gut gemacht, {STR_VAR_2}!\p"
	.string "Das sollte euch als Ansporn dienen!\n"
	.string "Powert eure DETEKTORen auf und macht\p"
	.string "euch auf die Suche! Ich warte auf\n"
	.string "interessante Berichte von euch allen!$"
	.endif
	.endif

gTVFindThatGamerText00::
	.ifdef ENGLISH
	.string "FIND THAT GAMER!\p"
	.string "Hey, all you gamers!\n"
	.string "How's your {STR_VAR_2} spinning?\p"
	.string "Like always, we'll cast our spotlight\n"
	.string "on a rare TRAINER who's visited the\l"
	.string "GAME CORNER!\p"
	.string "Today, our no. 1 gamer is…\n"
	.string "{STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "WER IST DER BESTE SPIELER!\p"
	.string "Ein dickes Hallo an alle Spieler!\n"
	.string "Wie läuft es beim {STR_VAR_2}?\p"
	.string "Wie immer suchen wir nach einem\n"
	.string "TRAINER, der die SPIELHALLE besucht.\p"
	.string "Unser heutiger Topspieler ist…\n"
	.string "{STR_VAR_1}!$"
	.endif
	.endif

gTVFindThatGamerText01::
	.ifdef ENGLISH
	.string "{STR_VAR_1} played the {STR_VAR_2} game\n"
	.string "and won a rare {STR_VAR_3} COINS.\p"
	.string "“When {STR_VAR_1} comes, we need to\n"
	.string "make sure we have enough COINS.”\p"
	.string "That's what the GAME CORNER clerks\n"
	.string "mutter when our gamer is in play!\p"
	.string "Viewers, it's best to watch your COINS\n"
	.string "like {STR_VAR_1} if you visit the GAME\l"
	.string "CORNER and play the {STR_VAR_2} game.\p"
	.string "This is live from the GAME CORNER--\n"
	.string "where you can feel the excitement!\p"
	.string "That's all for today!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} hat\n"
	.string "{STR_VAR_2} gespielt und\l"
	.string "{STR_VAR_3} MÜNZEn gewonnen.\p"
	.string "“Wenn {STR_VAR_1} hier ist, müssen wir\n"
	.string "darauf achten, genug MÜNZEn vorrätig\l"
	.string "zu haben.”\p"
	.string "Das sagen die Angestellten der\n"
	.string "SPIELHALLE, wenn unser TRAINER im\l"
	.string "Spiel ist!\p"
	.string "Solltet ihr die SPIELHALLE besuchen\n"
	.string "und {STR_VAR_2} spielen, dann\p"
	.string "achtet so gut auf eure MÜNZEn, wie\n"
	.string "{STR_VAR_1} das tut.\p"
	.string "Das war unser Live-Bericht aus der\n"
	.string "SPIELHALLE - wo euch vor Spannung der\l"
	.string "Atem stockt!\p"
	.string "Auf Wiedersehen bis zum nächsten Mal!$"
	.endif
	.endif

gTVFindThatGamerText02::
	.ifdef ENGLISH
	.string "{STR_VAR_1} played the {STR_VAR_2} game\n"
	.string "and lost {STR_VAR_3} COINS.\p"
	.string "“When {STR_VAR_1} comes, our COIN\n"
	.string "sales seem to increase.”\p"
	.string "That's what the GAME CORNER clerks\n"
	.string "say when our gamer is in play!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} hat {STR_VAR_2}\n"
	.string "gespielt und {STR_VAR_3} MÜNZEn verloren.\p"
	.string "“Dank {STR_VAR_1} verkaufen wir viele\n"
	.string "MÜNZEn.”\p"
	.string "Das sagen die Angestellten der\n"
	.string "SPIELHALLE, wenn dieser Spieler\l"
	.string "sein Glück versucht.$"
	.endif
	.endif

gTVFindThatGamerText03::
	.ifdef ENGLISH
	.string "Viewers, it's best to watch your COINS\n"
	.string "like {STR_VAR_1} if you visit the GAME\l"
	.string "CORNER and play the {STR_VAR_2} game.\p"
	.string "This is live from the GAME CORNER--\n"
	.string "where you can feel the excitement!\p"
	.string "That's all for today!$"
	.else
	.ifdef GERMAN
	.string "Solltet ihr die SPIELHALLE besuchen\n"
	.string "und {STR_VAR_2} spielen, dann\p"
	.string "achtet so gut auf eure MÜNZEn, wie\n"
	.string "{STR_VAR_1} das tut.\p"
	.string "Das war unser Live-Bericht aus der\n"
	.string "SPIELHALLE - wo euch vor Spannung der\l"
	.string "Atem stockt!\p"
	.string "Auf Wiedersehen bis zum nächsten Mal!$"
	.endif
	.endif

gTVBreakingNewsText00::
	.ifdef ENGLISH
	.string "BREAKING NEWS TV!$"
	.else
	.ifdef GERMAN
	.string "NACHRICHTEN-TV!$"
	.endif
	.endif

gTVBreakingNewsText01::
	.ifdef ENGLISH
	.string "Rare {STR_VAR_2} caught by\n"
	.string "{STR_VAR_1}!\p"
	.string "We're live from the vicinity of\n"
	.string "{STR_VAR_3}!\p"
	.string "{STR_VAR_1} successfully captured\n"
	.string "a rare {STR_VAR_2} earlier here!$"
	.else
	.ifdef GERMAN
	.string "Seltenes {STR_VAR_2} wurde \n"
	.string "von {STR_VAR_1} gefangen!\p"
	.string "Wir berichten live aus der Gegend\n"
	.string "von {STR_VAR_3}!\p"
	.string "{STR_VAR_1} hat es geschafft, hier ein\n"
	.string "seltenes {STR_VAR_2} zu fangen!$"
	.endif
	.endif

gTVBreakingNewsText02::
	.ifdef ENGLISH
	.string "When {STR_VAR_1} encountered the rare\n"
	.string "{STR_VAR_2}, the TRAINER sent out\l"
	.string "the POKéMON {STR_VAR_3}.$"
	.else
	.ifdef GERMAN
	.string "Als {STR_VAR_1} das seltene {STR_VAR_2}\n"
	.string "bemerkte, hat der TRAINER das POKéMON\l"
	.string "{STR_VAR_3} eingesetzt.$"
	.endif
	.endif

gTVBreakingNewsText03::
	.ifdef ENGLISH
	.string "In the battle, the number of POKé\n"
	.string "BALLS thrown by the TRAINER was {STR_VAR_1}.\p"
	.string "Ultimately, the rare POKéMON was\n"
	.string "caught by the {STR_VAR_2} used last.$"
	.else
	.ifdef GERMAN
	.string "Beim Versuch, das seltene POKéMON zu\n"
	.string "fangen, hat der TRAINER {STR_VAR_1} POKéBÄLLE\l"
	.string "geworfen.\p"
	.string "Schließlich konnte das POKéMON mit\n"
	.string "einem {STR_VAR_2} gefangen werden!$"
	.endif
	.endif

gTVBreakingNewsText04::
	.ifdef ENGLISH
	.string "In that instant, {STR_VAR_2}\n"
	.string "echoed with {STR_VAR_1}'s roars of\l"
	.string "triumphant joy.\p"
	.string "I must say I'm a little envious of\n"
	.string "{STR_VAR_1}. I'd love to roar, too.\p"
	.string "…That ends the live feed from\n"
	.string "the happy scene!$"
	.else
	.ifdef GERMAN
	.string "Und in {STR_VAR_2} hallten die\n"
	.string "Freudenschreie von {STR_VAR_1} wider.\p"
	.string "Ich muss gestehen, ich bin ein wenig\n"
	.string "neidisch auf {STR_VAR_1}. Auch ich\l"
	.string "hätte gerne einen Grund für\p"
	.string "Freudenschreie.\n"
	.string "Das war’s für heute!\l"
	.string "Bis zum nächsten Mal!$"
	.endif
	.endif

gTVBreakingNewsText05::
	.ifdef ENGLISH
	.string "{STR_VAR_1} fails to capture a rare\n"
	.string "{STR_VAR_2}!\p"
	.string "We're live from the vicinity of\n"
	.string "{STR_VAR_3}!\p"
	.string "It was here that {STR_VAR_1} failed\n"
	.string "to capture a rare {STR_VAR_2}!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} hat es nicht geschafft, das\n"
	.string "seltene POKéMON {STR_VAR_2} zu fangen!\p"
	.string "Wir berichten live aus der Region\n"
	.string "um {STR_VAR_3}!\p"
	.string "Hier war es, wo {STR_VAR_1} bei dem\n"
	.string "Versuch gescheitert ist, das seltene\l"
	.string "{STR_VAR_2} zu fangen!$"
	.endif
	.endif

gTVBreakingNewsText06::
	.ifdef ENGLISH
	.string "When {STR_VAR_1} encountered the rare\n"
	.string "{STR_VAR_2}, the TRAINER sent out\l"
	.string "the POKéMON {STR_VAR_3}.$"
	.else
	.ifdef GERMAN
	.string "Als {STR_VAR_1} auf das seltene\n"
	.string "POKéMON {STR_VAR_2} getroffen ist, hat\l"
	.string "der TRAINER {STR_VAR_3} eingesetzt.$"
	.endif
	.endif

gTVBreakingNewsText07::
	.ifdef ENGLISH
	.string "The TRAINER made the {STR_VAR_2}\n"
	.string "use the move {STR_VAR_1}.\p"
	.string "Without meaning to, the TRAINER\n"
	.string "made the rare POKéMON faint…$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2} sollte die Attacke\n"
	.string "{STR_VAR_1} einsetzen.\p"
	.string "Ohne es zu beabsichtigen, besiegte\n"
	.string "der TRAINER damit das seltene POKéMON…$"
	.endif
	.endif

gTVBreakingNewsText12::
	.ifdef ENGLISH
	.string "However, {STR_VAR_1} panicked at\n"
	.string "the sight of the rare {STR_VAR_2}.\p"
	.string "In confusion, the TRAINER ordered\n"
	.string "{STR_VAR_3} to attack.\p"
	.string "Without meaning to, the TRAINER\n"
	.string "made the rare POKéMON faint.$"
	.else
	.ifdef GERMAN
	.string "Aber {STR_VAR_1} verfiel in Panik, als es\n"
	.string "das seltene {STR_VAR_2} sah.\p"
	.string "Hektisch setzte der TRAINER daraufhin\n"
	.string "{STR_VAR_3} ein.\p"
	.string "Doch dadurch wurde das seltene\n"
	.string "POKéMON unabsichtlich besiegt…$"
	.endif
	.endif

gTVBreakingNewsText08::
	.ifdef ENGLISH
	.string "In that instant, {STR_VAR_2}\n"
	.string "echoed with {STR_VAR_1}'s shrieks of\l"
	.string "frustration…$"
	.else
	.ifdef GERMAN
	.string "Und so hallten in der Gegend um\n"
	.string "{STR_VAR_2} die frustrierten\l"
	.string "Schreie von {STR_VAR_1} wider…$"
	.endif
	.endif

gTVBreakingNewsText09::
	.ifdef ENGLISH
	.string "However, {STR_VAR_1} seemed to run\n"
	.string "out of POKé BALLS.\p"
	.string "The TRAINER had to break off\n"
	.string "the battle with the rare {STR_VAR_2}.\p"
	.string "In that instant, {STR_VAR_3}\n"
	.string "echoed with {STR_VAR_1}'s shrieks of\l"
	.string "frustration…$"
	.else
	.ifdef GERMAN
	.string "Aber {STR_VAR_1} schien nicht genug\n"
	.string "POKéBÄLLe zu haben.\p"
	.string "Und so musste der TRAINER den Kampf\n"
	.string "mit dem seltenen {STR_VAR_2} abbrechen.\p"
	.string "Und so hallten in der Gegend um\n"
	.string "{STR_VAR_3} die frustrierten\l"
	.string "Schreie von {STR_VAR_1} wider…$"
	.endif
	.endif

gTVBreakingNewsText10::
	.ifdef ENGLISH
	.string "However, the {STR_VAR_2} fled without\n"
	.string "warning.\p"
	.string "In that instant, {STR_VAR_3}\n"
	.string "echoed with {STR_VAR_1}'s shrieks of\l"
	.string "frustration…$"
	.else
	.ifdef GERMAN
	.string "Aber {STR_VAR_2} floh ohne Vorwarnung\n"
	.string "aus dem Kampf.\p"
	.string "Und so hallten in der Gegend um\n"
	.string "{STR_VAR_3} die frustrierten\l"
	.string "Schreie von {STR_VAR_1} wider…$"
	.endif
	.endif

gTVBreakingNewsText11::
	.ifdef ENGLISH
	.string "I must say I feel for {STR_VAR_1}.\n"
	.string "Why, it makes me want to shriek, too.\p"
	.string "…That ends the live feed from\n"
	.string "the melancholy scene!$"
	.else
	.ifdef GERMAN
	.string "Ich fühle mit {STR_VAR_1}.\n"
	.string "Ich möchte am liebsten auch schreien.\p"
	.string "Das war unser Live-Bericht über eine\n"
	.string "tragische Begebenheit.$"
	.endif
	.endif

gTVSecretBaseVisitText00::
	.ifdef ENGLISH
	.string "Hello, folks!\n"
	.string "It's time again for\l"
	.string "a SECRET BASE VISIT.\p"
	.string "Today, we visit the SECRET BASE\n"
	.string "of {STR_VAR_1}.\p"
	.string "How has {STR_VAR_1} personalized\n"
	.string "the SECRET BASE?\p"
	.string "Let's find out!\n"
	.string "… … … … … …$"
	.else
	.ifdef GERMAN
	.string "Hallo Leute!!!\n"
	.string "Es ist wieder Zeit für die\l"
	.string "REPORTAGE AUS DER GEHEIMBASIS.\p"
	.string "Heute besuchen wir die GEHEIMBASIS\n"
	.string "von {STR_VAR_1}.\p"
	.string "Wie hat {STR_VAR_1} sie eingerichtet?\p"
	.string "Lasst uns das herausfinden!\n"
	.string "… … … … …\l"
	.string "…$"
	.endif
	.endif

gTVSecretBaseVisitText01::
	.ifdef ENGLISH
	.string "Oh!\n"
	.string "How marvelous!\p"
	.string "This {STR_VAR_2}…\n"
	.string "It's not what one would expect to\l"
	.string "find here!$"
	.else
	.ifdef GERMAN
	.string "Oh…\n"
	.string "Ganz großartig!\p"
	.string "{STR_VAR_2}…\n"
	.string "Dieses Item hätte man hier sicher\l"
	.string "nicht erwartet!$"
	.endif
	.endif

gTVSecretBaseVisitText02::
	.ifdef ENGLISH
	.string "Oh!\n"
	.string "How remarkable!\p"
	.string "There isn't a single piece\n"
	.string "of furniture or interior goods!\p"
	.string "Mere mortals couldn't hope to\n"
	.string "imitate this bold statement!\p"
	.string "It's simple, but it bursts, yes,\n"
	.string "bursts with wildness!\p"
	.string "My hat's off to you, {STR_VAR_1}.\n"
	.string "It had to be you!$"
	.else
	.ifdef GERMAN
	.string "Oh…\n"
	.string "Einfach bemerkenswert!\p"
	.string "Hier gibt es kein einziges\n"
	.string "Möbelstück!\p"
	.string "Normale Sterbliche werden diese\n"
	.string "Kühnheit der Einrichtung nicht\l"
	.string "nachahmen können!\p"
	.string "Ein einfacher Stil, der aber durch seine\n"
	.string "Wildheit besticht.\p"
	.string "Ich ziehe den Hut vor dir, {STR_VAR_1}.\n"
	.string "So etwas kannst nur du leisten.$"
	.endif
	.endif

gTVSecretBaseVisitText03::
	.ifdef ENGLISH
	.string "Oh! I see!\n"
	.string "With perfect clarity, I see it!\p"
	.string "This {STR_VAR_2} being here…\n"
	.string "It sends an effective message!$"
	.else
	.ifdef GERMAN
	.string "Oh, verstehe!\n"
	.string "Ich habe es klar vor Augen.\p"
	.string "Dieses Item hier - {STR_VAR_2}…\n"
	.string "Es sagt alles!$"
	.endif
	.endif

gTVSecretBaseVisitText04::
	.ifdef ENGLISH
	.string "Oh! I see!\n"
	.string "With perfect clarity, I see it!\p"
	.string "This space is kept deliberately\n"
	.string "clear of interior items!\p"
	.string "It sends an effective message!$"
	.else
	.ifdef GERMAN
	.string "Oh, verstehe!\n"
	.string "Ich habe es klar vor Augen.\p"
	.string "Dieser Raum ist ganz bewusst frei\n"
	.string "von allen Gegenständen gehalten!\p"
	.string "Die Interpretation dieses Raumes ist\n"
	.string "eindeutig.$"
	.endif
	.endif

gTVSecretBaseVisitText05::
	.ifdef ENGLISH
	.string "Wheeew!\p"
	.string "The pairing of the {STR_VAR_2}\n"
	.string "with the {STR_VAR_3}!\p"
	.string "It's a dream combination if there\n"
	.string "ever was one!$"
	.else
	.ifdef GERMAN
	.string "Wuhuuu!\p"
	.string "{STR_VAR_2} gepaart mit\n"
	.string "{STR_VAR_3}!\p"
	.string "Eine absolute Traumkombination!$"
	.endif
	.endif

gTVSecretBaseVisitText06::
	.ifdef ENGLISH
	.string "Wheeew!\p"
	.string "The placement of this {STR_VAR_2}\n"
	.string "right here…\p"
	.string "It has a presence that fills\n"
	.string "the entire SECRET BASE!$"
	.else
	.ifdef GERMAN
	.string "Wuhuuu!\p"
	.string "{STR_VAR_2} - und das an dieser\n"
	.string "Stelle!\p"
	.string "Es prägt das Bild der GEHEIMBASIS.$"
	.endif
	.endif

gTVSecretBaseVisitText07::
	.ifdef ENGLISH
	.string "Wheeew!\p"
	.string "There's nothing in place here.\p"
	.string "This empty space has an effect on\n"
	.string "the entire SECRET BASE.$"
	.else
	.ifdef GERMAN
	.string "Wuhuuu!\p"
	.string "Hier gibt es rein gar nichts!\p"
	.string "Und dieses Nichts prägt diese\n"
	.string "GEHEIMBASIS!$"
	.endif
	.endif

gTVSecretBaseVisitText08::
	.ifdef ENGLISH
	.string "Oh!\n"
	.string "Here comes {STR_VAR_1}!\l"
	.string "Let's challenge the TRAINER!\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"
	.else
	.ifdef GERMAN
	.string "Oh!\n"
	.string "Da kommt {STR_VAR_1}!\l"
	.string "Stellen wir den TRAINER auf die Probe!\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "…$"
	.endif
	.endif

gTVSecretBaseVisitText09::
	.ifdef ENGLISH
	.string "Sigh…\n"
	.string "I've got to hand it to {STR_VAR_1}.\p"
	.string "The TRAINER's POKéMON were truly\n"
	.string "worthy of the CHAMPION's title.\p"
	.string "They gave ample proof of {STR_VAR_1}'s\n"
	.string "toughness as a TRAINER.\p"
	.string "That the {STR_VAR_2} knew the move\n"
	.string "{STR_VAR_3}…\p"
	.string "It shows you what sort of a TRAINER\n"
	.string "{STR_VAR_1} is.\p"
	.string "Certainly, it was quite a lesson!$"
	.else
	.ifdef GERMAN
	.string "Seufz…\n"
	.string "Dies werde ich {STR_VAR_1} geben.\p"
	.string "Die POKéMON dieses TRAINERs verdienen\n"
	.string "wirklich den Titel CHAMP.\p"
	.string "Sie beweisen die Stärke von\n"
	.string "{STR_VAR_1}.\p"
	.string "Und dass {STR_VAR_2} die Attacke\n"
	.string "{STR_VAR_3} kennt…\p"
	.string "Das macht deutlich, welche Art von\n"
	.string "TRAINER wir bei {STR_VAR_1} vor uns\l"
	.string "haben.\p"
	.string "Nun, das war wirklich interessant!$"
	.endif
	.endif

gTVSecretBaseVisitText10::
	.ifdef ENGLISH
	.string "Aiyeeh!\n"
	.string "I've got to hand it to {STR_VAR_1}.\p"
	.string "The TRAINER's POKéMON were\n"
	.string "monstrously tough!\p"
	.string "They gave ample proof of {STR_VAR_1}'s\n"
	.string "tenacity as a TRAINER.\p"
	.string "That the {STR_VAR_2} knew the move\n"
	.string "{STR_VAR_3}…\p"
	.string "It shows you what sort of a TRAINER\n"
	.string "{STR_VAR_1} is.\p"
	.string "Certainly, it was quite a lesson!$"
	.else
	.ifdef GERMAN
	.string "Ahaaa…\n"
	.string "Dies werde ich {STR_VAR_1} geben.\p"
	.string "Die POKéMON dieses TRAINERs sind\n"
	.string "wirklich unglaublich stark!\p"
	.string "Sie beweisen die Hartnäckigkeit\n"
	.string "von {STR_VAR_1}.\p"
	.string "Und dass {STR_VAR_2} die Attacke\n"
	.string "{STR_VAR_3} kennt…\p"
	.string "Das macht deutlich, welche Art von\n"
	.string "TRAINER wir bei {STR_VAR_1} vor uns\l"
	.string "haben.\p"
	.string "Nun, das war wirklich interessant!$"
	.endif
	.endif

gTVSecretBaseVisitText11::
	.ifdef ENGLISH
	.string "Wheeew!\n"
	.string "I've got to hand it to {STR_VAR_1}.\p"
	.string "The TRAINER's POKéMON were clearly\n"
	.string "raised in a well-balanced manner.\p"
	.string "They gave ample proof of {STR_VAR_1}'s\n"
	.string "thoughtfulness as a TRAINER.\p"
	.string "That the {STR_VAR_2} knew the move\n"
	.string "{STR_VAR_3}…\p"
	.string "It shows you what sort of a TRAINER\n"
	.string "{STR_VAR_1} is.\p"
	.string "Certainly, it was quite a lesson!$"
	.else
	.ifdef GERMAN
	.string "Ahaaa…\n"
	.string "Dies werde ich {STR_VAR_1} geben.\p"
	.string "Die POKéMON dieses TRAINERs sind\n"
	.string "wirklich sehr ausgewogen aufgezogen\l"
	.string "worden!\p"
	.string "Sie beweisen die Reife und Intelligenz\n"
	.string "von {STR_VAR_1}.\p"
	.string "Und dass {STR_VAR_2} die Attacke\n"
	.string "{STR_VAR_3} kennt…\p"
	.string "Das macht deutlich, welche Art von\n"
	.string "TRAINER wir bei {STR_VAR_1} vor uns\l"
	.string "haben.\p"
	.string "Nun, das war wirklich interessant!$"
	.endif
	.endif

gTVSecretBaseVisitText12::
	.ifdef ENGLISH
	.string "Well, well!\n"
	.string "I've got to hand it to {STR_VAR_1}.\p"
	.string "The TRAINER's POKéMON showed\n"
	.string "great promise for future growth.\p"
	.string "They represented {STR_VAR_1}'s\n"
	.string "hopes and dreams.\p"
	.string "That the {STR_VAR_2} knew the move\n"
	.string "{STR_VAR_3}…\p"
	.string "It shows you what sort of a TRAINER\n"
	.string "{STR_VAR_1} is.\p"
	.string "Certainly, it was quite a lesson!$"
	.else
	.ifdef GERMAN
	.string "Ahaaa…\n"
	.string "Dies werde ich {STR_VAR_1} geben.\p"
	.string "Die POKéMON dieses TRAINERs\n"
	.string "haben mit Sicherheit eine große\l"
	.string "Zukunft vor sich!\p"
	.string "Sie stehen für die Träume und\n"
	.string "Hoffnungen von {STR_VAR_1}.\p"
	.string "Und dass {STR_VAR_2} die Attacke\n"
	.string "{STR_VAR_3} kennt…\p"
	.string "Das macht deutlich, welche Art von\n"
	.string "TRAINER wir bei {STR_VAR_1} vor uns\l"
	.string "haben.\p"
	.string "Nun, das war wirklich interessant!$"
	.endif
	.endif

gTVSecretBaseVisitText13::
	.ifdef ENGLISH
	.string "I must say, what a superb SECRET BASE\n"
	.string "it was!\p"
	.string "Viewers, if you have the chance,\n"
	.string "do visit {STR_VAR_1}'s SECRET BASE.\p"
	.string "Until next time, I bid you adieu!$"
	.else
	.ifdef GERMAN
	.string "Ich muss sagen, das war wirklich eine\n"
	.string "prächtige GEHEIMBASIS!\p"
	.string "Meine lieben Zuschauer, wenn ihr die\n"
	.string "Gelegenheit bekommt, die GEHEIMBASIS\p"
	.string "von {STR_VAR_1} zu besuchen, dann\n"
	.string "macht das unbedingt!\p"
	.string "Bis zum nächsten Mal! Auf Wiedersehen!$"
	.endif
	.endif

gTVPokemonLotteryWinnerFlashReportText00::
	.ifdef ENGLISH
	.string "It's exciting!\n"
	.string "It's dramatic!\p"
	.string "It's the POKéMON LOTTERY\n"
	.string "WINNER FLASH REPORT!\p"
	.string "Hello! We're coming at you live from\n"
	.string "the POKéMON LOTTERY CORNER on\l"
	.string "the ground floor of the LILYCOVE\l"
	.string "DEPARTMENT STORE!\p"
	.string "Like it always happens, another\n"
	.string "lucky TRAINER appeared today!\p"
	.string "That TRAINER's name…\n"
	.string "{STR_VAR_1}!\p"
	.string "{STR_VAR_1} won the {STR_VAR_2} prize\n"
	.string "and took home the {STR_VAR_3}!\p"
	.string "{STR_VAR_1}!\n"
	.string "Congratulations!\p"
	.string "Viewers, don't just watch,\n"
	.string "get in on the action!\p"
	.string "All of us at the LILYCOVE DEPARTMENT\n"
	.string "STORE look forward to your next visit!\p"
	.string "This has been a live broadcast from\n"
	.string "the LILYCOVE DEPARTMENT STORE,\l"
	.string "offering you the greatest selection\l"
	.string "in all HOENN!$"
	.else
	.ifdef GERMAN
	.string "Sie ist aufregend!\n"
	.string "Sie ist spannend!\p"
	.string "Die POKéMON-LOTTERIE REPORTAGE!\p"
	.string "Hallo und herzlich willkommen! Wir\n"
	.string "berichten live über die POKéMON-\l"
	.string "LOTTERIE im Erdgeschoss des\l"
	.string "EINKAUFSZENTRUMs von SEEGRASULB!\p"
	.string "Und wie immer treffen wir auch heute\n"
	.string "einen glücklichen TRAINER!\p"
	.string "Ein TRAINER namens…\n"
	.string "{STR_VAR_1}!\p"
	.string "{STR_VAR_1} hat den {STR_VAR_2}\n"
	.string "gewonnen und nimmt\l"
	.string "{STR_VAR_3} mit nach Hause!\p"
	.string "{STR_VAR_1}!\n"
	.string "Herzlichen Glückwunsch!\p"
	.string "Und ihr vor den Fernsehgeräten! Schaut\n"
	.string "euch nicht nur das Glück anderer an!\l"
	.string "Werdet selbst aktiv!\p"
	.string "Wir hier im EINKAUFSZENTRUM von\n"
	.string "SEEGRASULB warten auf euch!\p"
	.string "Und das war’s für heute live aus dem\n"
	.string "EINKAUFSZENTRUM von SEEGRASULB -\l"
	.string "wo man die größte Auswahl an Waren in\l"
	.string "ganz HOENN findet!$"
	.endif
	.endif

gTVThePokemonBattleSeminarText00::
	.ifdef ENGLISH
	.string "THE POKéMON BATTLE SEMINAR!\p"
	.string "We examine battles to see what\n"
	.string "lessons we may learn from others.\p"
	.string "Today's case study is on {STR_VAR_1}'s\n"
	.string "battle.\p"
	.string "{STR_VAR_1}'s {STR_VAR_2} was\n"
	.string "battling one {STR_VAR_3}…$"
	.else
	.ifdef GERMAN
	.string "DAS SEMINAR FÜR POKéMON-KÄMPFE\p"
	.string "Wir analysieren hier Kämpfe, um zu\n"
	.string "schauen, was wir von anderen lernen\l"
	.string "können.\p"
	.string "Heute nehmen wir uns den Kampf von\n"
	.string "{STR_VAR_1} vor.\p"
	.string "{STR_VAR_2} von {STR_VAR_1} hat gegen\n"
	.string "ein {STR_VAR_3} gekämpft…$"
	.endif
	.endif

gTVThePokemonBattleSeminarText01::
	.ifdef ENGLISH
	.string "And it used the move {STR_VAR_3}\n"
	.string "on the {STR_VAR_2}…\p"
	.string "Hmm… {STR_VAR_1}!\n"
	.string "That's the wrong thing to do!$"
	.else
	.ifdef GERMAN
	.string "Und es hat {STR_VAR_2} mit der Attacke\n"
	.string "{STR_VAR_3} angegriffen…\p"
	.string "Hmm… {STR_VAR_1}!\n"
	.string "Das war völlig falsch.$"
	.endif
	.endif

gTVThePokemonBattleSeminarText02::
	.ifdef ENGLISH
	.string "In addition to the doomed move,\n"
	.string "the TRAINER's {STR_VAR_1} also knew$"
	.else
	.ifdef GERMAN
	.string "Aber das war noch nicht das Schlimmste!\n"
	.string "Das {STR_VAR_1} von diesem TRAINER\l"
	.string "setzte außerdem diese Attacke(n) ein:$"
	.endif
	.endif

gTVThePokemonBattleSeminarText03::
	.ifdef ENGLISH
	.string "the moves {STR_VAR_1}, {STR_VAR_2},\n"
	.string "and {STR_VAR_3}.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1}, {STR_VAR_2}\n"
	.string "und {STR_VAR_3}.$"
	.endif
	.endif

gTVThePokemonBattleSeminarText04::
	.ifdef ENGLISH
	.string "the moves {STR_VAR_1} and\n"
	.string "{STR_VAR_2}.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} und {STR_VAR_2}.$"
	.endif
	.endif

gTVThePokemonBattleSeminarText05::
	.ifdef ENGLISH
	.string "the move {STR_VAR_2}.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}.$"
	.endif
	.endif

gTVThePokemonBattleSeminarText06::
	.ifdef ENGLISH
	.string "So, in this situation, what should\n"
	.string "the TRAINER have used?\p"
	.string "… … … … … …\n"
	.string "The move {STR_VAR_1}!\p"
	.string "The move {STR_VAR_1} would have been\n"
	.string "absolutely better than {STR_VAR_2}.\p"
	.string "Viewers, I urge you to learn from this\n"
	.string "case and battle with intelligence!\p"
	.string "Until next time, farewell!$"
	.else
	.ifdef GERMAN
	.string "Nun, welche Attacke sollte ein TRAINER\n"
	.string "in dieser Situation besser einsetzen?\p"
	.string "… … … … …\n"
	.string "…\l"
	.string "Die Attacke {STR_VAR_1}!\p"
	.string "{STR_VAR_1} wäre viel besser als\n"
	.string "{STR_VAR_2} gewesen!\p"
	.string "Ich bitte euch: Lernt aus diesen\n"
	.string "Fehlern und kämpft mit Intelligenz!\p"
	.string "Bis zum nächsten Mal! Macht’s gut!$"
	.endif
	.endif

gTVTrainerFanClubText00::
	.ifdef ENGLISH
	.string "All together now!\n"
	.string "TRAINER FAN CLUB!\p"
	.string "MC: How's everyone groovin'?\n"
	.string "Today, we've rounded up the fans of\l"
	.string "the hyper-popular TRAINER {STR_VAR_1}!\p"
	.string "FANS: Wrooooooaaaaah!\p"
	.string "FANS: {STR_VAR_1}!\p"
	.string "MC: Everyone!\n"
	.string "How do you like {STR_VAR_1}?!\p"
	.string "FANS: We love {STR_VAR_1}!\p"
	.string "MC: What do you love about\n"
	.string "{STR_VAR_1}?!$"
	.else
	.ifdef GERMAN
	.string "Und jetzt alle zusammen!\n"
	.string "TRAINER-FANCLUB!!!\p"
	.string "MC: Und wie sieht’s bei euch aus?!?\p"
	.string "Heute haben wir die Fans des mega-\n"
	.string "hyper-beliebten TRAINERs\l"
	.string "{STR_VAR_1} zusammengerufen!\p"
	.string "FANs: Juhuuuuuuuuuuuuuu!\p"
	.string "FANs: {STR_VAR_1}!\p"
	.string "MC: Ich frage euch!\n"
	.string "Wie findet ihr {STR_VAR_1}?!?\p"
	.string "FANs: Wir lieben {STR_VAR_1}!!!\p"
	.string "MC: Und was liebt ihr an dem\n"
	.string "TRAINER {STR_VAR_1}?!?$"
	.endif
	.endif

gTVTrainerFanClubText01::
	.ifdef ENGLISH
	.string "FANS: Their cool way of throwing\n"
	.string "POKé BALLS!$"
	.else
	.ifdef GERMAN
	.string "FANs: Dieser TRAINER wirft die\n"
	.string "POKéBÄLLe super cool!$"
	.endif
	.endif

gTVTrainerFanClubText02::
	.ifdef ENGLISH
	.string "FANS: Their adorable way of running!$"
	.else
	.ifdef GERMAN
	.string "FANs: Er rennt anbetungswürdig!$"
	.endif
	.endif

gTVTrainerFanClubText03::
	.ifdef ENGLISH
	.string "FANS: How the TRAINER turns tough\n"
	.string "when the going gets tough!$"
	.else
	.ifdef GERMAN
	.string "FANs: Dieser TRAINER zeigt Stärke,\n"
	.string "wenn es wirklich hart wird!$"
	.endif
	.endif

gTVTrainerFanClubText04::
	.ifdef ENGLISH
	.string "FANS: The TRAINER's knowledge of\n"
	.string "POKéMON!$"
	.else
	.ifdef GERMAN
	.string "FANs: Sein Wissen über POKéMON!$"
	.endif
	.endif

gTVTrainerFanClubText05::
	.ifdef ENGLISH
	.string "FANS: The TRAINER's kindness toward\n"
	.string "all POKéMON!$"
	.else
	.ifdef GERMAN
	.string "FANs: Er ist nett zu allen POKéMON!$"
	.endif
	.endif

gTVTrainerFanClubText06::
	.ifdef ENGLISH
	.string "FANS: The TRAINER's amazing\n"
	.string "BIKE-riding techniques!$"
	.else
	.ifdef GERMAN
	.string "FANs: Dieser TRAINER ist ein wahrer\n"
	.string "Meister im FAHRRAD Fahren.$"
	.endif
	.endif

gTVTrainerFanClubText07::
	.ifdef ENGLISH
	.string "FANS: The TRAINER's impressive\n"
	.string "item-buying style!$"
	.else
	.ifdef GERMAN
	.string "FANs: Er beeindruckt durch die Art, wie\n"
	.string "er Items kauft.$"
	.endif
	.endif

gTVTrainerFanClubText08::
	.ifdef ENGLISH
	.string "FANS: The TRAINER's charming way\n"
	.string "of nicknaming POKéMON!$"
	.else
	.ifdef GERMAN
	.string "FANs: Dieser TRAINER gibt den POKéMON\n"
	.string "sehr schöne Kosenamen!$"
	.endif
	.endif

gTVTrainerFanClubText09::
	.ifdef ENGLISH
	.string "FANS: The TRAINER's nifty style of\n"
	.string "decorating a SECRET BASE!$"
	.else
	.ifdef GERMAN
	.string "FANs: Der TRAINER hat seine\n"
	.string "GEHEIMBASIS total schick eingerichtet!$"
	.endif
	.endif

gTVTrainerFanClubText10::
	.ifdef ENGLISH
	.string "FANS: The TRAINER's bold ways of\n"
	.string "using TMs!$"
	.else
	.ifdef GERMAN
	.string "FANs: Der TRAINER setzt TMs kühn ein!$"
	.endif
	.endif

gTVTrainerFanClubText11::
	.ifdef ENGLISH
	.string "MC: As you've just seen, {STR_VAR_1}\n"
	.string "is hot! Like, too hot to touch, yow!\p"
	.string "Among {STR_VAR_1}'s FANS\n"
	.string "there's a special slogan!\p"
	.string "MC: When I say {STR_VAR_1},\n"
	.string "you say…\p"
	.string "FANS: {STR_VAR_2}!\p"
	.string "FANS: {STR_VAR_3}!\p"
	.string "FANS: {STR_VAR_2}!\p"
	.string "FANS: {STR_VAR_3}!\p"
	.string "MC: That's right, when someone says,\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Come back with, “{STR_VAR_2}\n"
	.string "{STR_VAR_3}!”\p"
	.string "That has such a unique ring to it!\n"
	.string "I can see why people become FANS\l"
	.string "of {STR_VAR_1}!\p"
	.string "Okay, you, in front of the TV, join us!\n"
	.string "All together now!\p"
	.string "MC: When I say {STR_VAR_1},\n"
	.string "you say…\p"
	.string "FANS: {STR_VAR_2}!\p"
	.string "FANS: {STR_VAR_3}!\p"
	.string "FANS: {STR_VAR_2}!\p"
	.string "FANS: {STR_VAR_3}!\p"
	.string "MC: Thanks for joining us, all you\n"
	.string "wild FANS of {STR_VAR_1}!\l"
	.string "That's the show! See you again!\p"
	.string "MC: When I say {STR_VAR_1},\n"
	.string "you say…\p"
	.string "FANS: {STR_VAR_2}!\p"
	.string "FANS: {STR_VAR_3}!$"
	.else
	.ifdef GERMAN
	.string "MC: Ihr habt es mitbekommen,\n"
	.string "{STR_VAR_1} ist heiß! Man könnte\l"
	.string "sich glatt verbrennen!\p"
	.string "Unter den FANs von {STR_VAR_1}\n"
	.string "gibt es einen Schlachtruf!\p"
	.string "MC: Ich sage {STR_VAR_1},\n"
	.string "ihr sagt…\p"
	.string "FANs: {STR_VAR_2}!\p"
	.string "FANs: {STR_VAR_3}!\p"
	.string "FANs: {STR_VAR_2}!\p"
	.string "FANs: {STR_VAR_3}!\p"
	.string "MC: Richtig! Sagt jemand\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Ruft ihr zurück “{STR_VAR_2}\n"
	.string "{STR_VAR_3}!”\p"
	.string "Das klingt einfach einzigartig!\n"
	.string "Ich kann verstehen, warum jemand\l"
	.string "FAN von {STR_VAR_1} wird!\p"
	.string "Okay, du da, vor dem Fernsehgerät!\n"
	.string "Schließ dich uns an! Alle zusammen!\p"
	.string "MC: Ich sage {STR_VAR_1},\n"
	.string "ihr sagt…\p"
	.string "FANs: {STR_VAR_2}!\p"
	.string "FANs: {STR_VAR_3}!\p"
	.string "FANs: {STR_VAR_2}!\p"
	.string "FANs: {STR_VAR_3}!\p"
	.string "MC: Ich bedanke mich bei euch,\n"
	.string "den rasenden FANs von {STR_VAR_1}!\p"
	.string "Das war unsere Show!\n"
	.string "Bis zum nächsten Mal!\p"
	.string "MC: Ich sage {STR_VAR_1},\n"
	.string "ihr sagt…\p"
	.string "FANs: {STR_VAR_2}!\p"
	.string "FANs: {STR_VAR_3}!$"
	.endif
	.endif

TVSpotTheCuties_Text_Intro::
	.ifdef ENGLISH
	.string "SPOT THE CUTIES!\n"
	.string "POKéMON IN RIBBONS!\p"
	.string "Hello, my sweet viewers!\p"
	.string "I just know you'll agree, but a POKéMON\n"
	.string "wearing RIBBONS is simply divine!\p"
	.string "Today, I want to share with you\n"
	.string "a lovely POKéMON I spotted while\l"
	.string "out on a stroll in town.\p"
	.string "Today's featured pretty POKéMON\n"
	.string "is {STR_VAR_1}'s {STR_VAR_2}.$"
	.else
	.ifdef GERMAN
	.string "HIER SIND DIE SÜSSEN!\n"
	.string "POKéMON UND IHRE BÄNDER!\p"
	.string "Hallo, meine Süßen!\p"
	.string "Ich weiß, ihr werdet mir mit Sicherheit\n"
	.string "zustimmen: POKéMON, die BÄNDer\l"
	.string "tragen, sind wirklich absolut süß!\p"
	.string "Heute möchte ich euch ein süßes\n"
	.string "POKéMON zeigen, das ich entdeckt habe,\l"
	.string "als ich durch die Stadt schlenderte.\p"
	.string "Unser heutiges süßes POKéMON gehört\n"
	.string "zu {STR_VAR_1} und ist ein {STR_VAR_2}.$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonsLow::
	.ifdef ENGLISH
	.string "The number of RIBBONS that\n"
	.string "{STR_VAR_2} wears is {STR_VAR_3}.\p"
	.string "It says a lot about how much\n"
	.string "{STR_VAR_1} adores the POKéMON.$"
	.else
	.ifdef GERMAN
	.string "Die Anzahl der BÄNDer,\n"
	.string "die {STR_VAR_2} trägt, ist {STR_VAR_3}!\p"
	.string "Und das lässt erkennen, wie sehr\n"
	.string "{STR_VAR_1} das POKéMON mag.$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonsMid::
	.ifdef ENGLISH
	.string "{STR_VAR_2} wears an amazing\n"
	.string "{STR_VAR_3} RIBBONS!\p"
	.string "It speaks volumes about {STR_VAR_1}'s\n"
	.string "commitment to the POKéMON!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2} trägt unglaubliche {STR_VAR_3}\n"
	.string "BÄNDer!\p"
	.string "Und das spricht Bände! Man erkennt\n"
	.string "die herzliche Bindung zwischen\l"
	.string "{STR_VAR_1} und dem POKéMON.$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonsHigh::
	.ifdef ENGLISH
	.string "{STR_VAR_2} wears an incredible\n"
	.string "{STR_VAR_3} RIBBONS!\p"
	.string "It shows you {STR_VAR_1}'s total\n"
	.string "dedication as a collector!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2} trägt fantastische \n"
	.string "{STR_VAR_3} BÄNDer!\p"
	.string "{STR_VAR_1} ist ein wahrer Sammler und\n"
	.string "POKéMON-Freund!$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonIntro::
	.ifdef ENGLISH
	.string "Let us take a closer look at the many\n"
	.string "RIBBONS worn by {STR_VAR_2}.$"
	.else
	.ifdef GERMAN
	.string "Schauen wir uns die BÄNDer von\n"
	.string "{STR_VAR_2} einmal näher an.$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonChampion::
	.ifdef ENGLISH
	.string "The CHAMPION RIBBON is especially\n"
	.string "fetching.\p"
	.string "{STR_VAR_2} received it upon entering\n"
	.string "the HALL OF FAME.\p"
	.string "It verily draws out the bravery\n"
	.string "of {STR_VAR_2}.\p"
	.string "{STR_VAR_2} and the CHAMP RIBBON!\n"
	.string "The combination is super effective!$"
	.else
	.ifdef GERMAN
	.string "Das BAND des CHAMPs ist besonders\n"
	.string "attraktiv.\p"
	.string "Als {STR_VAR_2} Einzug in die RUHMES-\n"
	.string "HALLE hielt, wurde es ihm überreicht.\p"
	.string "Der Mut von {STR_VAR_2} wird damit\n"
	.string "unterstrichen.\p"
	.string "{STR_VAR_2} und das BAND des CHAMPs!\n"
	.string "Eine absolut passende Kombination!$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonCool::
	.ifdef ENGLISH
	.string "The COOL RIBBON is especially\n"
	.string "fetching.\p"
	.string "{STR_VAR_2} received it for winning\n"
	.string "a COOL CONTEST.\p"
	.string "It verily draws out the coolness\n"
	.string "of {STR_VAR_2}.\p"
	.string "{STR_VAR_2} and the COOL RIBBON!\n"
	.string "The combination is super effective!$"
	.else
	.ifdef GERMAN
	.string "Das BAND der COOLNESS ist besonders\n"
	.string "attraktiv.\p"
	.string "{STR_VAR_2} hat es bekommen, als es den\n"
	.string "COOLNESS-WETTBEWERB gewonnen\l"
	.string "hat.\p"
	.string "Die COOLNESS von {STR_VAR_2} wird so\n"
	.string "noch mehr hervorgehoben.\p"
	.string "{STR_VAR_2} und das BAND der COOLNESS!\n"
	.string "Eine perfekte Kombination!$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonBeauty::
	.ifdef ENGLISH
	.string "The BEAUTY RIBBON is especially\n"
	.string "fetching.\p"
	.string "{STR_VAR_2} received it for winning\n"
	.string "a BEAUTY CONTEST.\p"
	.string "It verily draws out the beauty\n"
	.string "of {STR_VAR_2}.\p"
	.string "{STR_VAR_2} and the BEAUTY RIBBON!\n"
	.string "The combination is super effective!$"
	.else
	.ifdef GERMAN
	.string "Das BAND der SCHÖNHEIT ist besonders\n"
	.string "attraktiv.\p"
	.string "{STR_VAR_2} hat es bekommen, als es den\n"
	.string "SCHÖNHEITSWETTBEWERB gewonnen\l"
	.string "hat.\p"
	.string "Die SCHÖNHEIT von {STR_VAR_2} wird so\n"
	.string "noch mehr hervorgehoben.\p"
	.string "{STR_VAR_2} und das BAND der SCHÖN-\n"
	.string "HEIT! Eine perfekte Kombination!$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonCute::
	.ifdef ENGLISH
	.string "The CUTE RIBBON is especially\n"
	.string "fetching.\p"
	.string "{STR_VAR_2} received it for winning\n"
	.string "a CUTE CONTEST.\p"
	.string "It verily draws out the cuteness\n"
	.string "of {STR_VAR_2}.\p"
	.string "{STR_VAR_2} and the CUTE RIBBON!\n"
	.string "The combination is super effective!$"
	.else
	.ifdef GERMAN
	.string "Das BAND der ANMUT ist besonders\n"
	.string "attraktiv.\p"
	.string "{STR_VAR_2} hat es bekommen, als es den\n"
	.string "ANMUTSWETTBEWERB gewonnen\l"
	.string "hat.\p"
	.string "Die ANMUT von {STR_VAR_2} wird so\n"
	.string "noch mehr hervorgehoben.\p"
	.string "{STR_VAR_2} und das BAND der ANMUT!\n"
	.string "Eine perfekte Kombination!$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonSmart::
	.ifdef ENGLISH
	.string "The SMART RIBBON is especially\n"
	.string "fetching.\p"
	.string "{STR_VAR_2} received it for winning\n"
	.string "a SMART CONTEST.\p"
	.string "It verily draws out the smartness\n"
	.string "of {STR_VAR_2}.\p"
	.string "{STR_VAR_2} and the SMART RIBBON!\n"
	.string "The combination is super effective!$"
	.else
	.ifdef GERMAN
	.string "Das BAND der KLUGHEIT ist besonders\n"
	.string "attraktiv.\p"
	.string "{STR_VAR_2} hat es bekommen, als es den\n"
	.string "KLUGHEITS-WETTBEWERB gewonnen\l"
	.string "hat.\p"
	.string "Die KLUGHEIT von {STR_VAR_2} wird so\n"
	.string "noch mehr hervorgehoben.\p"
	.string "{STR_VAR_2} und das BAND der KLUGHEIT!\n"
	.string "Eine perfekte Kombination!$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonTough::
	.ifdef ENGLISH
	.string "The TOUGH RIBBON is especially\n"
	.string "fetching.\p"
	.string "{STR_VAR_2} received it for winning\n"
	.string "a TOUGH CONTEST.\p"
	.string "It verily draws out the toughness\n"
	.string "of {STR_VAR_2}.\p"
	.string "{STR_VAR_2} and the TOUGH RIBBON!\n"
	.string "The combination is super effective!$"
	.else
	.ifdef GERMAN
	.string "Das BAND der STÄRKE ist besonders\n"
	.string "attraktiv.\p"
	.string "{STR_VAR_2} hat es bekommen, als es den\n"
	.string "STÄRKEWETTBEWERB gewonnen\l"
	.string "hat.\p"
	.string "Die STÄRKE von {STR_VAR_2} wird so\n"
	.string "noch mehr hervorgehoben.\p"
	.string "{STR_VAR_2} und das BAND der STÄRKE!\n"
	.string "Eine perfekte Kombination!$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonWinning::
	.ifdef ENGLISH
	.string "The WINNING RIBBON is especially\n"
	.string "fetching.\p"
	.string "{STR_VAR_2} received it for its feats\n"
	.string "at the BATTLE TOWER.\p"
	.string "It verily draws out the mightiness\n"
	.string "of {STR_VAR_2}.\p"
	.string "{STR_VAR_2} and the WINNING RIBBON!\n"
	.string "The combination is super effective!$"
	.else
	.ifdef GERMAN
	.string "Das BAND des GEWINNERs ist besonders\n"
	.string "attraktiv.\p"
	.string "{STR_VAR_2} hat es bekommen, als\n"
	.string "Anerkennung seiner Leistung im\l"
	.string "DUELLTURM.\p"
	.string "Das Talent von {STR_VAR_2} wird so\n"
	.string "noch mehr hervorgehoben.\p"
	.string "{STR_VAR_2} und das BAND des\n"
	.string "GEWINNERs! Eine perfekte Kombination!$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonVictory::
	.ifdef ENGLISH
	.string "The VICTORY RIBBON is especially\n"
	.string "fetching.\p"
	.string "{STR_VAR_2} received it for its feats\n"
	.string "at the BATTLE TOWER.\p"
	.string "It verily draws out the incredible\n"
	.string "mightiness of {STR_VAR_2}.\p"
	.string "{STR_VAR_2} and the VICTORY RIBBON!\n"
	.string "The combination is super effective!$"
	.else
	.ifdef GERMAN
	.string "Das BAND des SIEGes ist besonders\n"
	.string "attraktiv.\p"
	.string "{STR_VAR_2} hat es bekommen, als\n"
	.string "Anerkennung seiner Leistung im\l"
	.string "DUELLTURM.\p"
	.string "Das unglaubliche Talent von\n"
	.string "{STR_VAR_2} wird so noch mehr\l"
	.string "hervorgehoben.\p"
	.string "{STR_VAR_2} und das BAND des\n"
	.string "SIEGes! Eine perfekte Kombination!$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonArtist::
	.ifdef ENGLISH
	.string "The ARTIST RIBBON is especially\n"
	.string "fetching.\p"
	.string "{STR_VAR_2} received it for being\n"
	.string "the model for an artist.\p"
	.string "It verily draws out the pop-star charm\n"
	.string "of {STR_VAR_2}.\p"
	.string "{STR_VAR_2} and the ARTIST RIBBON!\n"
	.string "The combination is super effective!$"
	.else
	.ifdef GERMAN
	.string "Das BAND des KÜNSTLERs ist besonders\n"
	.string "attraktiv.\p"
	.string "{STR_VAR_2} hat es bekommen, als\n"
	.string "Anerkennung seiner Leistung als\l"
	.string "Model für einen Künstler.\p"
	.string "Der Charme von {STR_VAR_2} wird so\n"
	.string "noch mehr hervorgehoben.\p"
	.string "{STR_VAR_2} und das BAND des\n"
	.string "KÜNSTLERs! Eine perfekte Kombination!$"
	.endif
	.endif

TVSpotTheCuties_Text_RibbonEffort::
	.ifdef ENGLISH
	.string "The Hard Worker RIBBON is\n"
	.string "especially fetching.\p"
	.string "{STR_VAR_2} received it for being\n"
	.string "an especially dedicated worker.\p"
	.string "It verily draws out the determination\n"
	.string "of {STR_VAR_2}.\p"
	.string "{STR_VAR_2} and the Hard Worker RIBBON!\n"
	.string "The combination is super effective!$"
	.else
	.ifdef GERMAN
	.string "Das FLEISS-BAND ist besonders\n"
	.string "attraktiv.\p"
	.string "{STR_VAR_2} hat es bekommen, als\n"
	.string "Anerkennung seiner harten Arbeit.\p"
	.string "Der Fleiß von {STR_VAR_2} wird so\n"
	.string "noch mehr hervorgehoben.\p"
	.string "{STR_VAR_2} und das FLEISS-BAND!\n"
	.string "Eine perfekte Kombination!$"
	.endif
	.endif

TVSpotTheCuties_Text_Outro::
	.ifdef ENGLISH
	.string "…Sigh…\p"
	.string "RIBBONS and POKéMON…\n"
	.string "They go so wonderfully together!\p"
	.string "Before I swoon,\n"
	.string "I bid you all farewell!$"
	.else
	.ifdef GERMAN
	.string "Seufz…\p"
	.string "BÄNDer und POKéMON…\n"
	.string "Was für eine wundervolle Kombination!\p"
	.string "Bevor ich vor Begeisterung in Ohnmacht\n"
	.string "falle, sage ich euch Lebewohl.$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText00::
	.ifdef ENGLISH
	.string "Greetings!\n"
	.string "It's time for POKéMON NEWS.\p"
	.string "We've got some uplifting news from\n"
	.string "the BATTLE FRONTIER.$"
	.else
	.ifdef GERMAN
	.string "Hallo! Es ist wieder Zeit für die\n"
	.string "POKéMON NACHRICHTEN!\p"
	.string "Wir haben unglaubliche Nachrichten von\n"
	.string "der KAMPFZONE.$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText01::
	.ifdef ENGLISH
	.string "The TRAINER {STR_VAR_1} set a new\n"
	.string "{STR_VAR_2}-win-streak record while on\l"
	.string "the BATTLE TOWER's SINGLE BATTLE\l"
	.string "ROOM challenge.\p"
	.string "Here's to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER {STR_VAR_1} hat den sagen-\n"
	.string "haften Rekord von {STR_VAR_2} Siegen in Folge\l"
	.string "in den EINZELKÄMPFen des DUELLTURMs\l"
	.string "aufgestellt.\p"
	.string "Ein Hoch auf dich, {STR_VAR_1}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText02::
	.ifdef ENGLISH
	.string "The TRAINER {STR_VAR_1} set a new\n"
	.string "{STR_VAR_2}-win-streak record while on\l"
	.string "the BATTLE TOWER's DOUBLE BATTLE\l"
	.string "ROOM challenge.\p"
	.string "Here's to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER {STR_VAR_1} hat den sagen-\n"
	.string "haften Rekord von {STR_VAR_2} Siegen in Folge\l"
	.string "in den DOPPELKÄMPFen des DUELLTURMs\l"
	.string "aufgestellt.\p"
	.string "Ein Hoch auf dich, {STR_VAR_1}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText03::
	.ifdef ENGLISH
	.string "The TRAINER {STR_VAR_1} set a new\n"
	.string "{STR_VAR_2}-win-streak record while on\l"
	.string "the BATTLE TOWER's MULTI BATTLE\l"
	.string "ROOM challenge.\p"
	.string "Here's to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER {STR_VAR_1} hat den sagen-\n"
	.string "haften Rekord von {STR_VAR_2} Siegen in Folge\l"
	.string "in den MULTIKÄMPFen des DUELLTURMs\l"
	.string "aufgestellt.\p"
	.string "Ein Hoch auf dich, {STR_VAR_1}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText04::
	.ifdef ENGLISH
	.string "The TRAINER {STR_VAR_1} set a new\n"
	.string "{STR_VAR_2}-win-streak record while on\l"
	.string "the BATTLE TOWER's LINK MULTI BATTLE\l"
	.string "ROOM challenge.\p"
	.string "Here's to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER {STR_VAR_1} hat den sagen-\n"
	.string "haften Rekord von {STR_VAR_2} Siegen in Folge\l"
	.string "in den LINK-MULTIKÄMPFen des\l"
	.string "DUELLTURMs aufgestellt.\p"
	.string "Ein Hoch auf dich, {STR_VAR_1}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText05::
	.ifdef ENGLISH
	.string "The TRAINER {STR_VAR_1} set a new\n"
	.string "{STR_VAR_2}-championship-streak record\l"
	.string "competing in the BATTLE DOME's\l"
	.string "SINGLE BATTLE Tournaments.\p"
	.string "Here's to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER {STR_VAR_1} hat den\n"
	.string "meisterhaften Rekord von {STR_VAR_2} Siegen\l"
	.string "in Folge in den EINZELKAMPF-\l"
	.string "Turnieren des KAMPFSTADIONs\p"
	.string "aufgestellt. Ein Hoch auf dich,\n"
	.string "{STR_VAR_1}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText06::
	.ifdef ENGLISH
	.string "The TRAINER {STR_VAR_1} set a new\n"
	.string "{STR_VAR_2}-championship-streak record\l"
	.string "competing in the BATTLE DOME's\l"
	.string "DOUBLE BATTLE Tournaments.\p"
	.string "Here's to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER {STR_VAR_1} hat den\n"
	.string "meisterhaften Rekord von {STR_VAR_2} Siegen\l"
	.string "in Folge im DOPPELKAMPF-Turnier\l"
	.string "des KAMPFSTADIONs aufgestellt.\p"
	.string "Ein Hoch auf dich, {STR_VAR_1}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText07::
	.ifdef ENGLISH
	.string "The TRAINER {STR_VAR_1} set a new\n"
	.string "{STR_VAR_2}-win-streak record while on\l"
	.string "the BATTLE FACTORY's Battle\l"
	.string "Swap Single challenge.\p"
	.string "Here's to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER {STR_VAR_1} hat den sagen-\n"
	.string "haften Rekord von {STR_VAR_2} Siegen in Folge\l"
	.string "in der Einzel-Wechselkampf-Herausfor-\l"
	.string "derung der KAMPFFABRIK aufgestellt.\p"
	.string "Ein Hoch auf dich, {STR_VAR_1}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText08::
	.ifdef ENGLISH
	.string "The TRAINER {STR_VAR_1} set a new\n"
	.string "{STR_VAR_2}-win-streak record while on\l"
	.string "the BATTLE FACTORY's Battle\l"
	.string "Swap Double challenge.\p"
	.string "Here's to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER {STR_VAR_1} hat den sagen-\n"
	.string "haften Rekord von {STR_VAR_2} Siegen in Folge\l"
	.string "in der Doppel-Wechselkampf-Herausfor-\l"
	.string "derung der KAMPFFABRIK aufgestellt.\p"
	.string "Ein Hoch auf dich, {STR_VAR_1}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText09::
	.ifdef ENGLISH
	.string "The TRAINER {STR_VAR_1} set a new\n"
	.string "record of clearing {STR_VAR_2} rooms\l"
	.string "while on the BATTLE PIKE's Battle\l"
	.string "Choice challenge.\p"
	.string "Here's to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER {STR_VAR_1} hat einen\n"
	.string "neuen Rekord aufgestellt: {STR_VAR_2} Räume\l"
	.string "der Kampfbahn-Herausforderung der\l"
	.string "KAMPFIPITIS wurden erobert.\p"
	.string "Ein Hoch auf dich, {STR_VAR_1}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText10::
	.ifdef ENGLISH
	.string "The TRAINER {STR_VAR_1} set a new\n"
	.string "{STR_VAR_2}-win-streak record while\l"
	.string "competing in the BATTLE ARENA's\l"
	.string "Set KO Tournaments.\p"
	.string "Here's to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER {STR_VAR_1} hat den sagen-\n"
	.string "haften Rekord von {STR_VAR_2} Siegen in Folge\l"
	.string "in dem K.O.-Teamturnier des\l"
	.string "KAMPFRINGs aufgestellt.\p"
	.string "Ein Hoch auf dich, {STR_VAR_1}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText11::
	.ifdef ENGLISH
	.string "The TRAINER {STR_VAR_1} set a new\n"
	.string "{STR_VAR_2}-win-streak record while on\l"
	.string "the BATTLE PALACE's SINGLE BATTLE\l"
	.string "HALL challenge.\p"
	.string "Here's to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER {STR_VAR_1} hat den sagen-\n"
	.string "haften Rekord von {STR_VAR_2} Siegen in Folge\l"
	.string "in den EINZELKAMPF-HALLEn des\l"
	.string "KAMPFPALASTes aufgestellt.\p"
	.string "Ein Hoch auf dich, {STR_VAR_1}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText12::
	.ifdef ENGLISH
	.string "The TRAINER {STR_VAR_1} set a new\n"
	.string "{STR_VAR_2}-win-streak record while on\l"
	.string "the BATTLE PALACE's DOUBLE BATTLE\l"
	.string "HALL challenge.\p"
	.string "Here's to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER {STR_VAR_1} hat den sagen-\n"
	.string "haften Rekord von {STR_VAR_2} Siegen in Folge\l"
	.string "in der DOPPELKAMPF-HALLE des\l"
	.string "KAMPFPALASTes aufgestellt.\p"
	.string "Ein Hoch auf dich, {STR_VAR_1}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText13::
	.ifdef ENGLISH
	.string "The TRAINER {STR_VAR_1} set a new\n"
	.string "record of clearing {STR_VAR_2} floors\l"
	.string "while on the BATTLE PYRAMID's\l"
	.string "Battle Quest challenge.\p"
	.string "Here's to {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER {STR_VAR_1} hat einen\n"
	.string "neuen Rekord aufgestellt: {STR_VAR_2} Ebenen\l"
	.string "der Kampfforschung-Herausforderung\l"
	.string "in der KAMPFPYRAMIDE wurden erobert.\p"
	.string "Ein Hoch auf dich, {STR_VAR_1}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText14::
	.ifdef ENGLISH
	.string "And to the three POKéMON, {STR_VAR_1},\n"
	.string "{STR_VAR_2}, and {STR_VAR_3}!\p"
	.string "Congratulations for your\n"
	.string "record-breaking performance!$"
	.else
	.ifdef GERMAN
	.string "Und auf die POKéMON {STR_VAR_1},\n"
	.string "{STR_VAR_2} und {STR_VAR_3}!\p"
	.string "Vielen Dank für eure alle Rekorde\n"
	.string "brechende Vorstellung!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText15::
	.ifdef ENGLISH
	.string "And to the two POKéMON, {STR_VAR_1}\n"
	.string "and {STR_VAR_2}!\p"
	.string "Congratulations for your\n"
	.string "record-breaking performance!$"
	.else
	.ifdef GERMAN
	.string "Und auf die POKéMON {STR_VAR_1}\n"
	.string "und {STR_VAR_2}!\p"
	.string "Vielen Dank für eure alle Rekorde\n"
	.string "brechende Vorstellung!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText16::
	.ifdef ENGLISH
	.string "And to the four POKéMON: {STR_VAR_1}!\p"
	.string "{STR_VAR_2}!\p"
	.string "{STR_VAR_3}!$"
	.else
	.ifdef GERMAN
	.string "Und auf die vier POKéMON: {STR_VAR_1}!\p"
	.string "{STR_VAR_2}!\p"
	.string "{STR_VAR_3}!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText17::
	.ifdef ENGLISH
	.string "And {STR_VAR_1}!\p"
	.string "Congratulations for your\n"
	.string "record-breaking performance!$"
	.else
	.ifdef GERMAN
	.string "Und {STR_VAR_1}!\p"
	.string "Vielen Dank für eure alle Rekorde\n"
	.string "brechende Vorstellung!$"
	.endif
	.endif

gTVPokemonNewsBattleFrontierText18::
	.ifdef ENGLISH
	.string "Let's hope for more record-setting\n"
	.string "feats from {STR_VAR_1} and the loyal\l"
	.string "POKéMON!\p"
	.string "That's the news on POKéMON NEWS!$"
	.else
	.ifdef GERMAN
	.string "Hoffen wir auf mehr Rekorde von\n"
	.string "{STR_VAR_1} und seinen treuen POKéMON!\p"
	.string "Und das waren die POKéMON NACHRICHTEN!$"
	.endif
	.endif

gTVWhatsNo1InHoennTodayText00::
	.ifdef ENGLISH
	.string "WHAT'S NO. 1 IN HOENN TODAY?\n"
	.string "Yes, it's that time again!\p"
	.string "Hello, viewers! Are you giving your\n"
	.string "best at whatever you do?\p"
	.string "Let's have a look at the TRAINER\n"
	.string "who did the very best today!\p"
	.string "Today's no. 1 TRAINER is none other\n"
	.string "than {STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "WER IST DIE NUMMER EINS IN HOENN?\n"
	.string "Ja, es ist mal wieder so weit!\p"
	.string "Hallo dort draußen vor den Bild-\n"
	.string "schirmen! Strengt ihr euch wirklich an?\p"
	.string "Schauen wir uns einen TRAINER an,\n"
	.string "der heute sein Bestes gegeben hat!\p"
	.string "Unsere heutige Nummer eins unter den\n"
	.string "TRAINERn ist {STR_VAR_1}!$"
	.endif
	.endif

gTVWhatsNo1InHoennTodayText01::
	.ifdef ENGLISH
	.string "In one day, {STR_VAR_1} spun the SLOTS\n"
	.string "at the GAME CORNER {STR_VAR_2} times.\p"
	.string "While playing, {STR_VAR_1} was heard\n"
	.string "murmuring, “For me, the reels don't\l"
	.string "even move…”\l"
	.string "Isn't that interesting?$"
	.else
	.ifdef GERMAN
	.string "An einem Tag hat {STR_VAR_1} {STR_VAR_2}-mal am\n"
	.string "EINARMIGEN BANDITen in der SPIELHALLE\l"
	.string "gespielt.\p"
	.string "Und währenddessen murmelte\n"
	.string "{STR_VAR_1}: “Irgendwie bewegt sich\l"
	.string "hier gar nichts.”\l"
	.string "Das ist doch wohl wirklich interessant!$"
	.endif
	.endif

gTVWhatsNo1InHoennTodayText02::
	.ifdef ENGLISH
	.string "In one day, {STR_VAR_1} played\n"
	.string "the ROULETTE game at the GAME\l"
	.string "CORNER {STR_VAR_2} times.\p"
	.string "While playing, {STR_VAR_1} shouted,\n"
	.string "“Let the balls decide!”\p"
	.string "The TRAINER's eyes were focused and\n"
	.string "the face showed concentration.$"
	.else
	.ifdef GERMAN
	.string "An einem Tag hat {STR_VAR_1} {STR_VAR_2}-mal\n"
	.string "ROULETTE in der SPIELHALLE\l"
	.string "gespielt.\p"
	.string "Und währenddessen rief\n"
	.string "{STR_VAR_1}: “Überlassen wir es der\l"
	.string "Kugel.”\p"
	.string "Die Augen des TRAINERs schauten sehr\n"
	.string "konzentriert auf das Spiel.$"
	.endif
	.endif

gTVWhatsNo1InHoennTodayText03::
	.ifdef ENGLISH
	.string "In one day, {STR_VAR_1} battled\n"
	.string "wild POKéMON {STR_VAR_2} times!\p"
	.string "Apparently, {STR_VAR_1}'s POKéMON\n"
	.string "have grown incomparably stronger.\p"
	.string "They appear eager to battle anywhere,\n"
	.string "anytime, and anyhow!$"
	.else
	.ifdef GERMAN
	.string "An einem Tag hat {STR_VAR_1} {STR_VAR_2}-mal\n"
	.string "gegen wilde POKéMON gekämpft.\p"
	.string "Offenbar sind die POKéMON von\n"
	.string "{STR_VAR_1} unvergleichlich stark\l"
	.string "geworden.\p"
	.string "Sie scheinen immer und überall kämpfen\n"
	.string "zu wollen!$"
	.endif
	.endif

gTVWhatsNo1InHoennTodayText04::
	.ifdef ENGLISH
	.string "In just one day, {STR_VAR_1} spun\n"
	.string "the BERRY BLENDER {STR_VAR_2} times!\p"
	.string "Toward the end, even {STR_VAR_1}\n"
	.string "seemed to get dizzy.\p"
	.string "The TRAINER appeared to totter\n"
	.string "around like a SPINDA!$"
	.else
	.ifdef GERMAN
	.string "An einem Tag hat {STR_VAR_1} {STR_VAR_2}-mal\n"
	.string "den BEERENMIXER betätigt.\p"
	.string "Am Ende schien es {STR_VAR_1} ein\n"
	.string "bisschen schwindelig zu sein.\p"
	.string "Der TRAINER stolperte herum wie\n"
	.string "ein PANDIR.$"
	.endif
	.endif

gTVWhatsNo1InHoennTodayText05::
	.ifdef ENGLISH
	.string "In just one day, {STR_VAR_1} planted\n"
	.string "{STR_VAR_2} BERRIES!\p"
	.string "As a result, {STR_VAR_1}'s clothes\n"
	.string "became filthy with dirt.\p"
	.string "Where the TRAINER planted, countless\n"
	.string "flowers have burst into bloom.\p"
	.string "The flowers are said to soothe\n"
	.string "the emotions of people.$"
	.else
	.ifdef GERMAN
	.string "An nur einem Tag hat {STR_VAR_1} {STR_VAR_2}\n"
	.string "BEEREn gepflanzt.\p"
	.string "Und dabei hat sich {STR_VAR_1} die\n"
	.string "Kleidung schmutzig gemacht.\p"
	.string "Dort, wo der TRAINER etwas gepflanzt\n"
	.string "hat, blühen nun zahllose Blumen.\p"
	.string "Man sagt, diese würden auf die Menschen\n"
	.string "beruhigend wirken.$"
	.endif
	.endif

gTVWhatsNo1InHoennTodayText06::
	.ifdef ENGLISH
	.string "In just one day, {STR_VAR_1} picked\n"
	.string "{STR_VAR_2} BERRIES!\p"
	.string "{STR_VAR_1}'s BAG became so filled\n"
	.string "with BERRIES, the TRAINER had trouble\l"
	.string "walking afterward!$"
	.else
	.ifdef GERMAN
	.string "An nur einem Tag hat {STR_VAR_1} {STR_VAR_2}\n"
	.string "BEEREn gepflückt.\p"
	.string "Der BEUTEL von {STR_VAR_1} wurde\n"
	.string "dadurch so schwer, dass der TRAINER\l"
	.string "Schwierigkeiten hatte, ihn zu tragen.$"
	.endif
	.endif

gTVWhatsNo1InHoennTodayText07::
	.ifdef ENGLISH
	.string "In just one day, {STR_VAR_1} obtained\n"
	.string "{STR_VAR_2} Battle Points!\p"
	.string "{STR_VAR_1} was later seen wrestling\n"
	.string "with the choice of exchanging\l"
	.string "the Battle Points for a cool item or\l"
	.string "a nifty interior decoration.\p"
	.string "The TRAINER reportedly was grinning\n"
	.string "while mulling options.$"
	.else
	.ifdef GERMAN
	.string "An nur einem Tag hat {STR_VAR_1} {STR_VAR_2}\n"
	.string "Gewinnpunkte erhalten.\p"
	.string "Später wurde beobachtet, dass\n"
	.string "{STR_VAR_1} Schwierigkeiten hatte,\l"
	.string "sich für einen der Preise zu\l"
	.string "entscheiden, die man für Gewinnpunkte\p"
	.string "eintauschen kann. Ein wirres Grinsen\n"
	.string "lag um den Mund des TRAINERs, als er\l"
	.string "sich entscheiden musste.$"
	.endif
	.endif

gTVWhatsNo1InHoennTodayText08::
	.ifdef ENGLISH
	.string "Well, isn't that something!\p"
	.string "{STR_VAR_1}!\n"
	.string "You're today's no. 1 TRAINER!\p"
	.string "Viewers, take heart from {STR_VAR_1}!\n"
	.string "You, too, can be no. 1 every day!$"
	.else
	.ifdef GERMAN
	.string "Also, wenn das nicht ausreicht…\p"
	.string "{STR_VAR_1}!\n"
	.string "Du bist heute unser TRAINER Nr. 1!\p"
	.string "Nehmt euch ein Beispiel daran! Auch ihr\n"
	.string "könnt zur Nummer eins werden!$"
	.endif
	.endif

TVSecretBaseSecrets_Text_Intro::
	.ifdef ENGLISH
	.string "SECRET BASE SECRETS!\p"
	.string "What do TRAINERS do in the secrecy\n"
	.string "of SECRET BASES?\p"
	.string "Today, we investigate {STR_VAR_1}'s\n"
	.string "SECRET BASE.\p"
	.string "Oh? It looks like {STR_VAR_2} has come\n"
	.string "for a visit.\p"
	.string "Let's have a peek!\p"
	.string "What will {STR_VAR_2} do?$"
	.else
	.ifdef GERMAN
	.string "GEHEIMNISSE DER GEHEIMBASIS!\p"
	.string "Was machen TRAINER in ihrer\n"
	.string "GEHEIMBASIS?\p"
	.string "Heute untersuchen wir die GEHEIMBASIS\n"
	.string "von {STR_VAR_1}.\p"
	.string "Hey! {STR_VAR_2} scheint zu Besuch zu\n"
	.string "sein.\p"
	.string "Dann schauen wir doch noch ein\n"
	.string "bisschen durch das Schlüsselloch.\p"
	.string "Was wird {STR_VAR_2} tun?$"
	.endif
	.endif

TVSecretBaseSecrets_Text_WhatWillPlayerDoNext1::
	.ifdef ENGLISH
	.string "What will {STR_VAR_2} do next?$"
	.else
	.ifdef GERMAN
	.string "Was wird {STR_VAR_2} als Nächstes tun?$"
	.endif
	.endif

TVSecretBaseSecrets_Text_WhatWillPlayerDoNext2::
	.ifdef ENGLISH
	.string "And now, what will {STR_VAR_2} do?$"
	.else
	.ifdef GERMAN
	.string "Und was wird {STR_VAR_2} nun machen?$"
	.endif
	.endif

TVSecretBaseSecrets_Text_TookXStepsBeforeLeaving::
	.ifdef ENGLISH
	.string "In the end, {STR_VAR_2} took {STR_VAR_3} steps\n"
	.string "in {STR_VAR_1}'s SECRET BASE before\l"
	.string "leaving.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2} hat {STR_VAR_3} Schritte in der\n"
	.string "GEHEIMBASIS von {STR_VAR_1} gemacht,\l"
	.string "bevor es Abschied nehmen hieß.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_BaseFailedToInterestPlayer::
	.ifdef ENGLISH
	.string "Hmm…\p"
	.string "It appears as if {STR_VAR_1}'s SECRET\n"
	.string "BASE failed to interest {STR_VAR_2}…$"
	.else
	.ifdef GERMAN
	.string "Hmm…\p"
	.string "Scheinbar ist die GEHEIMBASIS von\n"
	.string "{STR_VAR_1} nicht interessant genug\l"
	.string "für {STR_VAR_2}…$"
	.endif
	.endif

TVSecretBaseSecrets_Text_PlayerEnjoyedBase::
	.ifdef ENGLISH
	.string "{STR_VAR_2} appears to have enjoyed\n"
	.string "{STR_VAR_1}'s SECRET BASE thoroughly.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2} scheint sich in der GEHEIM-\n"
	.string "BASIS von {STR_VAR_1} wirklich wohl\l"
	.string "gefühlt zu haben.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_PlayerHugeFanOfBase::
	.ifdef ENGLISH
	.string "{STR_VAR_2} appears to have become\n"
	.string "a huge fan of {STR_VAR_1}'s\l"
	.string "SECRET BASE.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2} scheint ein großer Fan der\n"
	.string "GEHEIMBASIS von {STR_VAR_1} geworden\l"
	.string "zu sein.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_Outro::
	.ifdef ENGLISH
	.string "Viewers may want to check out\n"
	.string "{STR_VAR_1}'s SECRET BASE, too.\p"
	.string "Tune in next time as we visit another\n"
	.string "SECRET BASE! Thanks for joining us!$"
	.else
	.ifdef GERMAN
	.string "Vielleicht möchten sich unsere\n"
	.string "Zuschauer die GEHEIMBASIS von\l"
	.string "{STR_VAR_1} ansehen.\p"
	.string "Schaltet wieder ein, wenn wir uns die\n"
	.string "nächste GEHEIMBASIS anschauen!\l"
	.string "Bis zum nächsten Mal! Auf Wiedersehen.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_StoppedMoving1::
	.ifdef ENGLISH
	.string "The visitor has stopped!\p"
	.string "The visitor isn't moving at all!\p"
	.string "Was {STR_VAR_1}'s SECRET BASE\n"
	.string "that unimpressive?$"
	.else
	.ifdef GERMAN
	.string "Der Besucher ist stehen geblieben!\p"
	.string "Er bewegt sich nicht einen Millimeter!\p"
	.string "Ist die GEHEIMBASIS von {STR_VAR_1} so\n"
	.string "uninteressant?$"
	.endif
	.endif

TVSecretBaseSecrets_Text_StoppedMoving2::
	.ifdef ENGLISH
	.string "The visitor has stopped!\p"
	.string "The visitor isn't moving at all!\p"
	.string "Is it fatigue?\n"
	.string "Has the visitor grown weary?$"
	.else
	.ifdef GERMAN
	.string "Der Besucher ist stehen geblieben!\p"
	.string "Er bewegt sich nicht einen Millimeter!\p"
	.string "Ist es Müdigkeit?\n"
	.string "Ist der Besucher eingeschlafen?$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedChair::
	.ifdef ENGLISH
	.string "The visitor sat down on a chair!\n"
	.string "The visitor is seated!\p"
	.string "Look at that look of delight!\p"
	.string "That chair must be very comfortable\n"
	.string "to get that response!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher setzt sich auf einen\n"
	.string "Stuhl!\p"
	.string "Schaut nur, sein glückliches Gesicht!\p"
	.string "Der Stuhl muss sehr bequem sein, wenn\n"
	.string "er so ein Gefühl hervorruft.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedBalloon::
	.ifdef ENGLISH
	.string "The visitor charged at a balloon!\p"
	.string "It burst!\n"
	.string "Oh, my goodness, it popped!\p"
	.string "The visitor appears startled by\n"
	.string "the sudden noise!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher hat einen Ballon ins\n"
	.string "Visier genommen!\p"
	.string "Er ist zerplatzt!\n"
	.string "Du meine Güte! Zerplatzt!!!\p"
	.string "Der Besucher scheint darüber sehr\n"
	.string "erschrocken zu sein.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedTent::
	.ifdef ENGLISH
	.string "The visitor entered a TENT!\p"
	.string "The visitor is running around!\p"
	.string "Oh, my, the visitor is frolicking!\p"
	.string "The visitor appears surprised by\n"
	.string "the TENT's size!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher hat ein ZELT betreten!\p"
	.string "Der Besucher rennt herum!\p"
	.string "Hui, der Besucher tollt richtig herum!\p"
	.string "Der Besucher scheint überrascht von\n"
	.string "der Größe des ZELTs zu sein!$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedPlant::
	.ifdef ENGLISH
	.string "The visitor is examining\n"
	.string "a potted plant!\p"
	.string "The visitor has surprisingly\n"
	.string "mature taste!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher betrachtet eingehend die\n"
	.string "Pflanze!\p"
	.string "Der Besucher hat einen ausgesprochen\n"
	.string "gereiften Geschmack!$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedGoldShield::
	.ifdef ENGLISH
	.string "The visitor is examining\n"
	.string "a GOLD SHIELD!\p"
	.string "The visitor's eyes appear to be\n"
	.string "lit up with wonder!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher untersucht das\n"
	.string "GOLDSCHILD!\p"
	.string "In den Augen des Besuchers spiegelt\n"
	.string "sich Verwunderung!$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedSilverShield::
	.ifdef ENGLISH
	.string "The visitor is examining\n"
	.string "a SILVER SHIELD!\p"
	.string "The visitor appears to be wide-eyed!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher untersucht das\n"
	.string "SILBERSCHILD!\p"
	.string "Die Augen des Besuchers werden immer\n"
	.string "größer!$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedGlassOrnament::
	.ifdef ENGLISH
	.string "The visitor is examining\n"
	.string "a GLASS ORNAMENT!\p"
	.string "Oh, no!\p"
	.string "The visitor is touching it!\p"
	.string "It's getting covered with\n"
	.string "fingerprints…$"
	.else
	.ifdef GERMAN
	.string "Der Besucher untersucht das\n"
	.string "GLASORNAMENT!\p"
	.string "Oh, nein! Nicht!\p"
	.string "Der Besucher fasst es an!\p"
	.string "Nun ist es übersät mit seinen\n"
	.string "Fingerabdrücken.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedTV::
	.ifdef ENGLISH
	.string "The visitor is watching television!\p"
	.string "Looks like we have a big fan of TV!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher schaut fern!\p"
	.string "Wir haben hier wohl einen großen\n"
	.string "Fan von Fernsehsendungen vor uns.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedMudBall::
	.ifdef ENGLISH
	.string "The visitor stomped on a MUD BALL!\p"
	.string "The visitor looks delighted!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher ist über einen LEHMBALL\n"
	.string "gestolpert!\p"
	.string "Er sieht erfreut aus.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedBag::
	.ifdef ENGLISH
	.string "…Oh?\p"
	.string "The visitor is reaching for their own\n"
	.string "BAG and rummaging about in it!\p"
	.string "The visitor pulled out\n"
	.string "one {STR_VAR_2}!\p"
	.string "Look at the visitor smile while\n"
	.string "holding up the {STR_VAR_2}!\p"
	.string "It's like a TV commercial!$"
	.else
	.ifdef GERMAN
	.string "Oh…\p"
	.string "Der Besucher sucht etwas in seinem\n"
	.string "BEUTEL.\p"
	.string "Er holt etwas heraus. Was ist es?\n"
	.string "Ah! {STR_VAR_2}!\p"
	.string "Schaut euch es euch an. Der Besucher\n"
	.string "lächelt glücklich, während er\l"
	.string "{STR_VAR_2} hochhält!\p"
	.string "Das ist ja fast wie in einem Werbespot!$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedCushion::
	.ifdef ENGLISH
	.string "The visitor grabs a cushion and…$"
	.else
	.ifdef GERMAN
	.string "Der Besucher nimmt sich ein Kissen und…$"
	.endif
	.endif

TVSecretBaseSecrets_Text_HitCushion::
	.ifdef ENGLISH
	.string "…begins hitting it!\p"
	.string "Is the visitor under a lot of stress?$"
	.else
	.ifdef GERMAN
	.string "Schlägt darauf ein?!?\p"
	.string "Er scheint unter sehr viel Stress\n"
	.string "zu stehen…$"
	.endif
	.endif

TVSecretBaseSecrets_Text_HuggedCushion::
	.ifdef ENGLISH
	.string "…hugs it tight!\p"
	.string "Could the visitor be feeling happy\n"
	.string "about something?$"
	.else
	.ifdef GERMAN
	.string "Umarmt es innig!\p"
	.string "Der Besucher scheint über irgendetwas\n"
	.string "sehr glücklich zu sein…$"
	.endif
	.endif

TVSecretBaseSecrets_Text_BattledWon::
	.ifdef ENGLISH
	.string "The visitor is chatting with\n"
	.string "{STR_VAR_1}!\p"
	.string "It looks like they're going to\n"
	.string "have a battle!\p"
	.string "And…\p"
	.string "It's the visitor!\n"
	.string "The visitor won an away match!\p"
	.string "The visitor is doing\n"
	.string "a victory dance!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher unterhält sich\n"
	.string "mit {STR_VAR_1}.\p"
	.string "Es sieht so aus, als wollten sie\n"
	.string "gegeneinander antreten!\p"
	.string "Und…\n"
	.string "Und?\p"
	.string "Der Besucher!\n"
	.string "Der Besucher hat den Kampf gewonnen!\p"
	.string "Er führt einen Siegestanz auf!$"
	.endif
	.endif

TVSecretBaseSecrets_Text_BattledLost::
	.ifdef ENGLISH
	.string "The visitor is chatting with\n"
	.string "{STR_VAR_1}!\p"
	.string "It looks like they're going to\n"
	.string "have a battle!\p"
	.string "And…\p"
	.string "It's {STR_VAR_1}!\n"
	.string "The visitor has lost!\p"
	.string "The visitor looks dejected!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher unterhält sich\n"
	.string "mit {STR_VAR_1}.\p"
	.string "Es sieht so aus, als wollten sie\n"
	.string "gegeneinander antreten!\p"
	.string "Und…\n"
	.string "Und?\p"
	.string "{STR_VAR_1}!\n"
	.string "{STR_VAR_1} hat den Kampf gewonnen!\p"
	.string "Der Besucher sieht deprimiert aus.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_DeclinedBattle::
	.ifdef ENGLISH
	.string "The visitor is chatting with\n"
	.string "{STR_VAR_1}!\p"
	.string "It looks like they're going to\n"
	.string "have a battle!\p"
	.string "And…\p"
	.string "No, the visitor has refused!\p"
	.string "There won't be a battle after all!\p"
	.string "Did the visitor find {STR_VAR_1}\n"
	.string "unappealing?$"
	.else
	.ifdef GERMAN
	.string "Der Besucher unterhält sich\n"
	.string "mit {STR_VAR_1}.\p"
	.string "Es sieht so aus, als wollten sie\n"
	.string "gegeneinander antreten!\p"
	.string "Und…\n"
	.string "Und?\p"
	.string "Nein! Der Besucher hat den Kampf\n"
	.string "abgelehnt. Sie werden nicht kämpfen.\p"
	.string "Ob der Besucher {STR_VAR_1}\n"
	.string "unsympathisch findet?$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedPoster::
	.ifdef ENGLISH
	.string "The visitor is staring intently\n"
	.string "at a poster!\p"
	.string "Is the poster to the visitor's\n"
	.string "liking?\p"
	.string "…But… There's something disturbing\n"
	.string "about the visitor's stares.$"
	.else
	.ifdef GERMAN
	.string "Der Besucher schaut sich aufmerksam\n"
	.string "ein Poster an!\p"
	.string "Gefällt ihm das Poster?\n"
	.string "… …\p"
	.string "Irgendetwas an dem Blick des Besuchers\n"
	.string "ist merkwürdig…$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedNoteMat::
	.ifdef ENGLISH
	.string "The visitor stepped on a NOTE MAT!\p"
	.string "…Hmm…\n"
	.string "The visitor composed a funny tune!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher tritt auf eine NOTEN-\n"
	.string "MATTE!\p"
	.string "Hmm…\n"
	.string "Er spielt eine lustige Melodie.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_BattledDraw::
	.ifdef ENGLISH
	.string "The visitor is chatting with\n"
	.string "{STR_VAR_1}!\p"
	.string "It looks like they're going to\n"
	.string "have a battle!\p"
	.string "And…\p"
	.string "It's a draw!\n"
	.string "Nothing's resolved!\p"
	.string "Both TRAINERS appear to be very\n"
	.string "disappointed!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher unterhält sich\n"
	.string "mit {STR_VAR_1}.\p"
	.string "Es sieht so aus, als wollten sie\n"
	.string "gegeneinander antreten!\p"
	.string "Und…\n"
	.string "Und?\p"
	.string "Oh, ein Unentschieden!\p"
	.string "Beide TRAINER scheinen sehr\n"
	.string "enttäuscht zu sein.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedSpinMat::
	.ifdef ENGLISH
	.string "The visitor stepped on\n"
	.string "a SPIN MAT!\p"
	.string "It looks like the visitor is dizzy!\p"
	.string "The visitor is tottering about!\n"
	.string "Look out!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher probiert die DREH-MATTE\n"
	.string "aus!\p"
	.string "Ihm wird offensichtlich schwindelig!\p"
	.string "Er stolpert herum!\n"
	.string "Hey, pass auf!$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedSandOrnament::
	.ifdef ENGLISH
	.string "The visitor is reaching for\n"
	.string "a SAND ORNAMENT!\p"
	.string "Oh!\p"
	.string "It crumbled!\n"
	.string "It's fallen apart!\p"
	.string "The visitor looks sheepish\n"
	.string "and guilty!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher zeigt Interesse an dem\n"
	.string "SANDORNAMENT!\p"
	.string "Oh, nein!\p"
	.string "Es ist zusammengefallen!\p"
	.string "Dem Besucher ist das mehr als peinlich!$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedDesk::
	.ifdef ENGLISH
	.string "The visitor is rubbing a desktop\n"
	.string "with their finger!\p"
	.string "Apparently, the visitor disapproves\n"
	.string "of dust!\p"
	.string "The visitor is surprisingly concerned\n"
	.string "about neatness!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher fährt mit den Fingern\n"
	.string "über den Schreibtisch.\p"
	.string "Er scheint den Staub darauf zu\n"
	.string "missbilligen.\p"
	.string "Ein Besucher, der Sauberkeit\n"
	.string "offensichtlich zu schätzen weiß.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedBrick::
	.ifdef ENGLISH
	.string "The visitor is staring at a BRICK!\p"
	.string "Perhaps the visitor is thinking about\n"
	.string "the object on the BRICK.$"
	.else
	.ifdef GERMAN
	.string "Der Besucher starrt fasziniert auf\n"
	.string "einen BACKSTEIN.\p"
	.string "Ihn interessiert wohl das Objekt,\n"
	.string "welches darauf steht.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedSolidBoard::
	.ifdef ENGLISH
	.string "The visitor is walking across\n"
	.string "the SOLID BOARD.\p"
	.string "The visitor keeps looking down.\p"
	.string "The visitor appears to be surprisingly\n"
	.string "timid and cautious!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher läuft über das SOLIDE\n"
	.string "BRETT.\p"
	.string "Er schaut nach unten und setzt\n"
	.string "vorsichtig Fuß vor Fuß.\p"
	.string "Ein vorsichtiger Charakter!$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedFence::
	.ifdef ENGLISH
	.string "The visitor is looking intently\n"
	.string "at a FENCE!\p"
	.string "Has a new idea for a trap popped\n"
	.string "into the visitor's head?$"
	.else
	.ifdef GERMAN
	.string "Der Besucher betrachtet den ZAUN.\p"
	.string "Hat er eine neue Idee für eine Falle\n"
	.string "entwickelt?$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedGlitterMat::
	.ifdef ENGLISH
	.string "The visitor stepped on\n"
	.string "a GLITTER MAT!\p"
	.string "The visitor is striking a variety\n"
	.string "of poses!\p"
	.string "The visitor appears to be fantasizing\n"
	.string "about being an idol!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher tritt auf die GLITZER-\n"
	.string "MATTE.\p"
	.string "Er stellt sich in verschiedene Posen.\p"
	.string "Er stellt sich offensichtlich vor, er\n"
	.string "wäre ein Fotomodell, das posieren muss.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedTire::
	.ifdef ENGLISH
	.string "The visitor is staring intently\n"
	.string "at a TIRE!\p"
	.string "Could the visitor be thinking about\n"
	.string "the kind of car that would use it?$"
	.else
	.ifdef GERMAN
	.string "Ein REIFEN hat das Interesse des\n"
	.string "Besuchers geweckt.\p"
	.string "Ob er an einen Wagen denkt, zu dem\n"
	.string "dieser REIFEN passen würde?$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedStand::
	.ifdef ENGLISH
	.string "The visitor climbed a STAND!\p"
	.string "The visitor is looking out across\n"
	.string "{STR_VAR_1}'s BASE from high up!\p"
	.string "And…\p"
	.string "Lets loose a roar!\n"
	.string "The visitor is roaring!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher stellt sich auf das\n"
	.string "PODEST.\p"
	.string "Nun kann er sich die GEHEIMBASIS von\n"
	.string "{STR_VAR_1} von oben anschauen.\p"
	.string "Und…\p"
	.string "Er brüllt wie ein Löwe!\n"
	.string "Er brüllt tatsächlich! Unglaublich!$"
	.endif
	.endif

TVSecretBaseSecrets_Text_BrokeDoor::
	.ifdef ENGLISH
	.string "The visitor charged headlong into\n"
	.string "a BREAKABLE DOOR!\p"
	.string "The visitor is laughing uproariously!$"
	.else
	.ifdef GERMAN
	.string "Kopfüber stürzt sich der Besucher\n"
	.string "durch die BRECHBARE TÜR.\p"
	.string "Und dabei lacht er wie ein Verrückter!$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedDoll::
	.ifdef ENGLISH
	.string "The visitor is talking to a DOLL!\p"
	.string "…It's a little creepy…$"
	.else
	.ifdef GERMAN
	.string "Der Besucher unterhält sich mit einer\n"
	.string "PUPPE.\p"
	.string "Äh…\n"
	.string "Das ist schon ein wenig unheimlich…$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedSlide::
	.ifdef ENGLISH
	.string "The visitor is climbing the ladder\n"
	.string "on a SLIDE!\p"
	.string "And…\p"
	.string "The visitor slid down!\p"
	.string "Looks like the visitor is having\n"
	.string "a grand old time!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher klettert die Leiter der\n"
	.string "RUTSCHE hinauf.\p"
	.string "Und…\p"
	.string "Rutscht hinunter!\p"
	.string "Er ist unbeschwert und hat ein\n"
	.string "kindliches Vergnügen daran.$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedSlideButDidntGoDown::
	.ifdef ENGLISH
	.string "The visitor is climbing the ladder\n"
	.string "on a SLIDE!\p"
	.string "And…\p"
	.string "The visitor went back down\n"
	.string "the ladder!\p"
	.string "Did the visitor suddenly chicken out?$"
	.else
	.ifdef GERMAN
	.string "Der Besucher klettert die Leiter der\n"
	.string "RUTSCHE hinauf.\p"
	.string "Und…\p"
	.string "Klettert die Leiter wieder hinunter!\p"
	.string "Er wird doch nicht etwa Angst vor\n"
	.string "der Rutsche haben?!?$"
	.endif
	.endif

TVSecretBaseSecrets_Text_UsedJumpMat::
	.ifdef ENGLISH
	.string "The visitor stepped on\n"
	.string "a JUMP MAT!\p"
	.string "The visitor jumped once!\p"
	.string "Jumped twice!\p"
	.string "And a successful landing!\p"
	.string "The visitor is clapping!\n"
	.string "What a solo performance!$"
	.else
	.ifdef GERMAN
	.string "Der Besucher tritt auf die SPRUNG-\n"
	.string "MATTE.\p"
	.string "Und springt ein Mal!\p"
	.string "Und zwei Mal!\p"
	.string "Was für eine perfekte Landung!\p"
	.string "Er applaudiert sich selbst!\n"
	.string "Was für eine grandiose Vorstellung!$"
	.endif
	.endif

gTVSafariFanClubText00::
	.ifdef ENGLISH
	.string "SAFARI FAN CLUB!\p"
	.string "REPORTER: All right, mates!\n"
	.string "Tossing them SAFARI BALLS, are you?\p"
	.string "You can bet I am here in the SAFARI\n"
	.string "ZONE chock-full of amazing POKéMON!\p"
	.string "Let's get with it and have a chat with\n"
	.string "this good fellow of a SAFARI GUIDE!\p"
	.string "All right, mate, how are the visiting\n"
	.string "TRAINERS looking?$"
	.else
	.ifdef GERMAN
	.string "SAFARI-FANCLUB!\p"
	.string "REPORTER: Also gut, Freunde!\n"
	.string "Ihr werft POKéBÄLLe, nicht wahr?\p"
	.string "Ich stehe hier in der SAFARI-ZONE, die\n"
	.string "vor fantastischer POKéMON nur so\l"
	.string "strotzt.\p"
	.string "Wir sollten uns mal mit einem\n"
	.string "TUTOR der SAFARI-ZONE\l"
	.string "unterhalten!\p"
	.string "Hallo, mein Freund. Wie machen sich die\n"
	.string "TRAINER, die ihr Glück hier versuchen?$"
	.endif
	.endif

gTVSafariFanClubText01::
	.ifdef ENGLISH
	.string "GUIDE: Everyone seems to be going\n"
	.string "hard at it.\p"
	.string "{STR_VAR_1} is doing especially well.\p"
	.string "Why, before, {STR_VAR_1} caught\n"
	.string "{STR_VAR_2} POKéMON.$"
	.else
	.ifdef GERMAN
	.string "TUTOR: Nun, jeder scheint sich\n"
	.string "hier wirklich anzustrengen.\p"
	.string "Besonders {STR_VAR_1} beweist großes\n"
	.string "Geschick.\p"
	.string "{STR_VAR_1} hat bereits {STR_VAR_2} POKéMON\n"
	.string "gefangen!$"
	.endif
	.endif

gTVSafariFanClubText02::
	.ifdef ENGLISH
	.string "The TRAINER is clever with {POKEBLOCK}S.\n"
	.string "Used {STR_VAR_2} that time, I think.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER setzt seine {POKEBLOCK} sehr\n"
	.string "intelligent ein. Ich glaube, er hat\p"
	.string "bisher {STR_VAR_2} davon verwendet.$"
	.endif
	.endif

gTVSafariFanClubText03::
	.ifdef ENGLISH
	.string "The TRAINER didn't use a single\n"
	.string "{POKEBLOCK}! Not a one!\p"
	.string "There's an expert for you.$"
	.else
	.ifdef GERMAN
	.string "Der TRAINER hat keinen {POKEBLOCK}\n"
	.string "verwendet. Nicht einen einzigen!\p"
	.string "Das ist ein wahrer Profi!$"
	.endif
	.endif

gTVSafariFanClubText04::
	.ifdef ENGLISH
	.string "REPORTER: Is that right, then?\p"
	.string "Sounds like our mate {STR_VAR_1}\n"
	.string "is a stout SAFARI master!\p"
	.string "GUIDE: I hope the TRAINER comes back\n"
	.string "and shows us that great technique.$"
	.else
	.ifdef GERMAN
	.string "REPORTER: Kann das stimmen?\p"
	.string "Das hört sich an, als sei unser Freund\n"
	.string "{STR_VAR_1} ein wahrer SAFARI-Meister!\p"
	.string "TUTOR: Ich hoffe, der TRAINER\n"
	.string "bringt uns seine Technik bei.$"
	.endif
	.endif

gTVSafariFanClubText05::
	.ifdef ENGLISH
	.string "GUIDE: No one seems to be doing\n"
	.string "very well.\p"
	.string "{STR_VAR_1} had it especially bad.\p"
	.string "Why, before, the TRAINER only\n"
	.string "managed to catch {STR_VAR_2} POKéMON.$"
	.else
	.ifdef GERMAN
	.string "TUTOR: Heute scheint niemand\n"
	.string "wahres Können zu beweisen.\p"
	.string "Besonders {STR_VAR_1} tut sich schwer.\p"
	.string "Bisher gelang es dem TRAINER lediglich\n"
	.string "{STR_VAR_2} POKéMON zu fangen.$"
	.endif
	.endif

gTVSafariFanClubText06::
	.ifdef ENGLISH
	.string "GUIDE: No one seems to be doing\n"
	.string "very well.\p"
	.string "{STR_VAR_1} had it especially bad.\p"
	.string "Why, before, the TRAINER didn't\n"
	.string "catch one POKéMON. Not a one!$"
	.else
	.ifdef GERMAN
	.string "TUTOR: Heute scheint niemand\n"
	.string "wahres Können zu beweisen.\p"
	.string "Besonders {STR_VAR_1} tut sich schwer.\p"
	.string "Bisher konnte der TRAINER kein\n"
	.string "einziges POKéMON fangen.$"
	.endif
	.endif

gTVSafariFanClubText07::
	.ifdef ENGLISH
	.string "The TRAINER does use {POKEBLOCK}S.\n"
	.string "Used {STR_VAR_2} that time, I think.\p"
	.string "But, boy, I wish the TRAINER would\n"
	.string "get a bit better at this.$"
	.else
	.ifdef GERMAN
	.string "Dabei setzt der TRAINER {POKEBLOCK} ein.\n"
	.string "Diesmal waren es, glaube ich, {STR_VAR_2}.\p"
	.string "Mann, ich würde mir wirklich wünschen,\n"
	.string "er würde sich geschickter anstellen.$"
	.endif
	.endif

gTVSafariFanClubText08::
	.ifdef ENGLISH
	.string "I think the TRAINER would have better\n"
	.string "luck using {POKEBLOCK}S, which weren't\l"
	.string "used at all that time.$"
	.else
	.ifdef GERMAN
	.string "Ich glaube, wenn der TRAINER {POKEBLOCK}\n"
	.string "verwenden würde, die er bisher noch\p"
	.string "nicht verwendet hat, hätte er gute\n"
	.string "Chancen.$"
	.endif
	.endif

gTVSafariFanClubText09::
	.ifdef ENGLISH
	.string "REPORTER: Is that right, then?\p"
	.string "Sounds like our mate {STR_VAR_1}\n"
	.string "needs more SAFARI seasoning.\p"
	.string "GUIDE: I hope the TRAINER visits\n"
	.string "over and over to get the hang of it.$"
	.else
	.ifdef GERMAN
	.string "REPORTER: Kann das stimmen?\p"
	.string "Das klingt, als ob unser Freund\n"
	.string "{STR_VAR_1} noch ein paar Übungs-\l"
	.string "stunden in der SAFARI-ZONE braucht.\p"
	.string "TUTOR: Ich hoffe, dieser\n"
	.string "TRAINER wird regelmäßig kommen, damit\l"
	.string "er irgendwann den Bogen raus hat.$"
	.endif
	.endif

gTVSafariFanClubText10::
	.ifdef ENGLISH
	.string "REPORTER: Quite right, it is!\n"
	.string "Facing up to challenges is important!\p"
	.string "Viewers, come on down to the SAFARI\n"
	.string "and make the challenge yourself!\p"
	.string "Until next time, cheerio!$"
	.else
	.ifdef GERMAN
	.string "REPORTER: Ein wahres Wort! Man muss\n"
	.string "sich den Herausforderungen stellen!\p"
	.string "Also, meine lieben Zuschauer, besucht\n"
	.string "die SAFARI-ZONE und stellt euch dieser\l"
	.string "Herausforderung!\p"
	.string "Bis zum nächsten Mal! Tschüss!$"
	.endif
	.endif

ContestLiveUpdates_Text_Intro::
	.ifdef ENGLISH
	.string "“POKéMON CONTEST LIVE UPDATES!”\p"
	.string "MC: Thanks for joining us!\p"
	.string "We're live from the just-ended\n"
	.string "{STR_VAR_1} site.\p"
	.string "The hall is still filled with\n"
	.string "an audience unwilling to leave.\p"
	.string "Spectator: {STR_VAR_2}!\p"
	.string "Spectator: {STR_VAR_3}!\p"
	.string "MC: As you've just heard, the CONTEST\n"
	.string "was won by the POKéMON {STR_VAR_2}\l"
	.string "of {STR_VAR_3}.\p"
	.string "Spectator: {STR_VAR_2}!\n"
	.string "You're the best!\p"
	.string "Spectator: {STR_VAR_3}!\n"
	.string "Way to go!\p"
	.string "MC: Let's hear what the fans have\n"
	.string "to say about this CONTEST.$"
	.else
	.ifdef GERMAN
	.string "“LIVE VON DEN POKéMON WETTBEWERBen”\p"
	.string "MC: Hallo und herzlich willkommen!\p"
	.string "Wir berichten live von dem gerade\n"
	.string "beendeten {STR_VAR_1}-WETTBEWERB.\p"
	.string "Die Halle ist immer noch gefüllt mit\n"
	.string "einem Publikum, das sich von den\l"
	.string "POKéMON nicht trennen kann.\p"
	.string "Zuschauer: {STR_VAR_2}!\p"
	.string "Zuschauer: {STR_VAR_3}!\p"
	.string "MC: Da haben wir gerade die Namen der\n"
	.string "Sieger gehört. {STR_VAR_3} hat mit dem\l"
	.string "POKéMON {STR_VAR_2} gewonnen!\p"
	.string "Zuschauer: {STR_VAR_2}! Du bist klasse!\p"
	.string "Zuschauer: {STR_VAR_3}! Weiter so!!!\p"
	.string "MC: Hören wir mal, was die Fans über\n"
	.string "diesen WETTBEWERB sagen.$"
	.endif
	.endif

ContestLiveUpdates_Text_WonBothRounds::
	.ifdef ENGLISH
	.string "Spectator: The {STR_VAR_2} was tops in\n"
	.string "both primary and secondary judging!\p"
	.string "That {STR_VAR_2} will keep winning!$"
	.else
	.ifdef GERMAN
	.string "Zuschauer: Das {STR_VAR_2} lag im\n"
	.string "1. und 2. Durchgang ganz vorne!\p"
	.string "Das {STR_VAR_2} wird auch weiter\n"
	.string "gewinnen.$"
	.endif
	.endif

ContestLiveUpdates_Text_BetterRound2::
	.ifdef ENGLISH
	.string "Spectator: The {STR_VAR_2} didn't do\n"
	.string "well in the primary judging, but it\l"
	.string "cleaned up in the secondary judging!\p"
	.string "It was a miraculous comeback\n"
	.string "for that {STR_VAR_2}. Yippee!$"
	.else
	.ifdef GERMAN
	.string "Zuschauer: Im 1. Durchgang war\n"
	.string "{STR_VAR_2} nicht überzeugend, aber im\l"
	.string "2. Durchgang fegte es alle vom Platz.\p"
	.string "Ein wundervolles Comeback für\n"
	.string "{STR_VAR_2}. Juhuuu!$"
	.endif
	.endif

ContestLiveUpdates_Text_EqualRounds::
	.ifdef ENGLISH
	.string "Spectator: The {STR_VAR_2} remained\n"
	.string "consistent throughout both primary\l"
	.string "and secondary judging.\p"
	.string "{STR_VAR_3} and the {STR_VAR_2},\n"
	.string "they're no ordinary combo!$"
	.else
	.ifdef GERMAN
	.string "Zuschauer: Das {STR_VAR_2} blieb im 1.\n"
	.string "und 2. Durchgang gleichbleibend\l"
	.string "erfolgreich.\p"
	.string "{STR_VAR_3} und das {STR_VAR_2} - keine\n"
	.string "gewöhnliche Kombination.$"
	.endif
	.endif

ContestLiveUpdates_Text_BetterRound1::
	.ifdef ENGLISH
	.string "Spectator: In terms of being {STR_VAR_1},\n"
	.string "that {STR_VAR_2} was outstanding.\p"
	.string "I hope it makes better appeals\n"
	.string "next time, though.$"
	.else
	.ifdef GERMAN
	.string "Zuschauer: {STR_VAR_1} - Unter diesem\n"
	.string "Aspekt war das {STR_VAR_2} einfach\l"
	.string "herausragend!\p"
	.string "Ich hoffe, es strengt sich nächstes Mal\n"
	.string "noch mehr an.$"
	.endif
	.endif

ContestLiveUpdates_Text_GotNervous::
	.ifdef ENGLISH
	.string "Spectator: When the {STR_VAR_2} got\n"
	.string "nervous, I couldn't stop myself from\l"
	.string "shouting encouragement.\p"
	.string "I'd like to say this to that\n"
	.string "{STR_VAR_2}, “Congratulations!”$"
	.else
	.ifdef GERMAN
	.string "Zuschauer: Als das {STR_VAR_2} nervös\n"
	.string "wurde, konnte ich mich nicht zurück-\l"
	.string "halten und habe es aufgemuntert.\p"
	.string "Ich möchte dem {STR_VAR_2}\n"
	.string "“Glückwunsch!” zurufen.$"
	.endif
	.endif

ContestLiveUpdates_Text_StartledFoes::
	.ifdef ENGLISH
	.string "Spectator: That {STR_VAR_2}'s appeal\n"
	.string "startled even me!\p"
	.string "{STR_VAR_2}, you were awesome!$"
	.else
	.ifdef GERMAN
	.string "Zuschauer: Der Auftritt von {STR_VAR_2}\n"
	.string "hat sogar mich erschreckt!\p"
	.string "{STR_VAR_2}, du warst großartig!$"
	.endif
	.endif

ContestLiveUpdates_Text_UsedCombo::
	.ifdef ENGLISH
	.string "Spectator: That {STR_VAR_2}'s combo\n"
	.string "appeal was stunning!\p"
	.string "It's shaken me to the core!$"
	.else
	.ifdef GERMAN
	.string "Zuschauer: Der Auftritt von {STR_VAR_2}\n"
	.string "war überwältigend!\p"
	.string "Ich bin immer noch ganz hin und weg.$"
	.endif
	.endif

ContestLiveUpdates_Text_ExcitingAppeal::
	.ifdef ENGLISH
	.string "Spectator: The winning {STR_VAR_2}'s\n"
	.string "appeal got my heart pounding!$"
	.else
	.ifdef GERMAN
	.string "Zuschauer: Der Auftritt des Siegers\n"
	.string "{STR_VAR_2} brachte mein Herz zum\l"
	.string "Rasen!$"
	.endif
	.endif

ContestLiveUpdates_Text_WasCool::
	.ifdef ENGLISH
	.string "{STR_VAR_2}!\n"
	.string "You were cool!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}!\n"
	.string "Du bist cool!$"
	.endif
	.endif

ContestLiveUpdates_Text_WasBeautiful::
	.ifdef ENGLISH
	.string "{STR_VAR_2}!\n"
	.string "You were beautiful!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}!\n"
	.string "Du bist schön!$"
	.endif
	.endif

ContestLiveUpdates_Text_WasCute::
	.ifdef ENGLISH
	.string "{STR_VAR_2}!\n"
	.string "You were cute!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}!\n"
	.string "Du bist anmutig!$"
	.endif
	.endif

ContestLiveUpdates_Text_WasSmart::
	.ifdef ENGLISH
	.string "{STR_VAR_2}!\n"
	.string "You were smart!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}!\n"
	.string "Du bist klug!$"
	.endif
	.endif

ContestLiveUpdates_Text_WasTough::
	.ifdef ENGLISH
	.string "{STR_VAR_2}!\n"
	.string "You were tough!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}!\n"
	.string "Du bist stark!$"
	.endif
	.endif

ContestLiveUpdates_Text_VeryExcitingAppeal::
	.ifdef ENGLISH
	.string "Spectator: The winning {STR_VAR_2}'s\n"
	.string "appeal still has my heart pounding!$"
	.else
	.ifdef GERMAN
	.string "Zuschauer: Der Auftritt des Siegers\n"
	.string "{STR_VAR_2} lässt mein Herz immer noch\l"
	.string "rasen!$"
	.endif
	.endif

ContestLiveUpdates_Text_VeryCool::
	.ifdef ENGLISH
	.string "{STR_VAR_2}!\n"
	.string "You're the last word in cool!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}!\n"
	.string "Cool ist dein zweiter Name!$"
	.endif
	.endif

ContestLiveUpdates_Text_VeryBeautiful::
	.ifdef ENGLISH
	.string "{STR_VAR_2}!\n"
	.string "You're the most beautiful!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}!\n"
	.string "Schönheit ist dein zweiter Name!$"
	.endif
	.endif

ContestLiveUpdates_Text_VeryCute::
	.ifdef ENGLISH
	.string "{STR_VAR_2}!\n"
	.string "You're simply the cutest!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}!\n"
	.string "Anmut ist dein zweiter Name!$"
	.endif
	.endif

ContestLiveUpdates_Text_VerySmart::
	.ifdef ENGLISH
	.string "{STR_VAR_2}!\n"
	.string "You're the smartest among the smart!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}!\n"
	.string "Klugheit ist dein zweiter Name!$"
	.endif
	.endif

ContestLiveUpdates_Text_VeryTough::
	.ifdef ENGLISH
	.string "{STR_VAR_2}!\n"
	.string "You're the toughest of the tough!$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_2}!\n"
	.string "Stärke ist dein zweiter Name!$"
	.endif
	.endif

ContestLiveUpdates_Text_TookBreak::
	.ifdef ENGLISH
	.string "Spectator: Even when the {STR_VAR_2}\n"
	.string "took a break from making appeals,\l"
	.string "I couldn't take my eyes off it.\p"
	.string "I'm captivated by that {STR_VAR_2}.$"
	.else
	.ifdef GERMAN
	.string "Zuschauer: Selbst als das {STR_VAR_2}\n"
	.string "eine Pause bei seinem Auftritt\l"
	.string "einlegte, konnte ich den Blick\p"
	.string "nicht abwenden! Ich war von dem\n"
	.string "{STR_VAR_2} wie gefangen.$"
	.endif
	.endif

ContestLiveUpdates_Text_GotStartled::
	.ifdef ENGLISH
	.string "Spectator: When the {STR_VAR_2} was\n"
	.string "startled by another POKéMON's appeal,\l"
	.string "I was close to tears.\p"
	.string "{STR_VAR_2}, you were resilient!\n"
	.string "Way to go!$"
	.else
	.ifdef GERMAN
	.string "Zuschauer: Als sich das {STR_VAR_2} vor\n"
	.string "den anderen POKéMON erschreckte,\l"
	.string "wäre ich fast in Tränen ausgebrochen.\p"
	.string "{STR_VAR_2}, du bist unverwüstlich!\n"
	.string "Weiter so!$"
	.endif
	.endif

ContestLiveUpdates_Text_MoveWonderful::
	.ifdef ENGLISH
	.string "Spectator: Oh…\n"
	.string "That {STR_VAR_2}'s {STR_VAR_3}!\l"
	.string "{STR_VAR_2}'s {STR_VAR_3}!\l"
	.string "{STR_VAR_2}'s {STR_VAR_3}!\l"
	.string "How could it be so wonderful?$"
	.else
	.ifdef GERMAN
	.string "Zuschauer: Oh…\p"
	.string "Die Attacke {STR_VAR_3} von\n"
	.string "{STR_VAR_2}!\l"
	.string "{STR_VAR_3} von {STR_VAR_2}!\l"
	.string "{STR_VAR_3} von {STR_VAR_2}!\l"
	.string "Wie kann etwas nur so wundervoll sein?$"
	.endif
	.endif

ContestLiveUpdates_Text_TalkAboutAnotherMon::
	.ifdef ENGLISH
	.string "MC: Well, there you have it. This place\n"
	.string "is full of the {STR_VAR_1}'s fans!\p"
	.string "I should also mention that another\n"
	.string "POKéMON, {STR_VAR_2}'s {STR_VAR_3}, \l"
	.string "caught my eye.\p"
	.string "{STR_VAR_2}'s {STR_VAR_3}…$"
	.else
	.ifdef GERMAN
	.string "MC: Nun, da hört ihr es. Hier sind lauter\n"
	.string "Fans von {STR_VAR_1}!\p"
	.string "Ich möchte aber auch erwähnen, dass\n"
	.string "das {STR_VAR_3} von {STR_VAR_2} meine\l"
	.string "Aufmerksamkeit erregt hat.\p"
	.string "{STR_VAR_3} von {STR_VAR_2}…$"
	.endif
	.endif

ContestLiveUpdates_Text_FailedToAppeal::
	.ifdef ENGLISH
	.string "It failed to make a single appeal during\n"
	.string "secondary judging out of nervousness.\p"
	.string "Next time, I would like to see this\n"
	.string "{STR_VAR_1} make even one appeal.$"
	.else
	.ifdef GERMAN
	.string "Es konnte im 2. Durchlauf vor lauter\n"
	.string "Nervosität keinen Auftritt bieten.\p"
	.string "Nächstes Mal möchte ich wenigstens\n"
	.string "einen Auftritt von {STR_VAR_1} sehen!$"
	.endif
	.endif

ContestLiveUpdates_Text_LastInBothRounds::
	.ifdef ENGLISH
	.string "It came dead last in both primary\n"
	.string "and secondary judging.\p"
	.string "I hope that {STR_VAR_1} will retrain this\n"
	.string "{STR_VAR_2} and erase the shame of\l"
	.string "this undisputed last-place finish.$"
	.else
	.ifdef GERMAN
	.string "In beiden Durchläufen konnte es\n"
	.string "absolut nicht überzeugen.\l"
	.string "Ich hoffe, dass das {STR_VAR_2} von\p"
	.string "{STR_VAR_1} demnächst besser\n"
	.string "vorbereitet ist und nicht wieder auf\l"
	.string "dem letzten Platz landet.$"
	.endif
	.endif

ContestLiveUpdates_Text_NotExcitingEnough::
	.ifdef ENGLISH
	.string "It failed to take advantage of\n"
	.string "the audience's excitement and make\l"
	.string "an appropriate appeal.\p"
	.string "We hope {STR_VAR_1} will learn how to get\n"
	.string "a feel for the audience and whip their\l"
	.string "excitement to a fever pitch next time.$"
	.else
	.ifdef GERMAN
	.string "Es schaffte es nicht, die Begeisterung\n"
	.string "des Publikums für sich zu nutzen und\l"
	.string "einen guten Auftritt zu bieten.\p"
	.string "Hoffen wir, dass {STR_VAR_1} ein Gespür für\n"
	.string "die Stimmung des Publikums bekommt und\l"
	.string "es das nächste Mal richtig anheizt.$"
	.endif
	.endif

ContestLiveUpdates_Text_LostAfterWinningRound1::
	.ifdef ENGLISH
	.string "While finishing first in the primary\n"
	.string "judging, its appeals in the secondary\l"
	.string "judging failed to click.\p"
	.string "It suffered a humiliating come-from-\n"
	.string "behind loss.\p"
	.string "I'm sure {STR_VAR_1} is studying how to\n"
	.string "make more effective appeals now.$"
	.else
	.ifdef GERMAN
	.string "Während es im 1. Durchlauf alle schlug,\n"
	.string "versagte es im 2. Durchlauf komplett.\p"
	.string "Es war wirklich erniedrigend.\p"
	.string "{STR_VAR_1} wird sich anstrengen, um\n"
	.string "überzeugende Auftritte hinlegen.$"
	.endif
	.endif

ContestLiveUpdates_Text_NeverExciting::
	.ifdef ENGLISH
	.string "The audience never got excited by its\n"
	.string "appeals during the secondary judging.\p"
	.string "We hope it will stop worrying about\n"
	.string "other POKéMON and learn to pitch\l"
	.string "its appeals to the audience more.$"
	.else
	.ifdef GERMAN
	.string "Im 2. Durchlauf konnte es das Publikum\n"
	.string "nicht für sich gewinnen.\l"
	.string "Hoffen wir, dass es sich demnächst\p"
	.string "nicht mehr so viele Gedanken über die\n"
	.string "anderen POKéMON macht und das Publikum\l"
	.string "überzeugen wird.$"
	.endif
	.endif

ContestLiveUpdates_Text_LostBySmallMargin::
	.ifdef ENGLISH
	.string "It lost to {STR_VAR_1}'s {STR_VAR_2}\n"
	.string "by only a small margin.\p"
	.string "It must be heartbreaking to come\n"
	.string "so close to victory only to fail.\p"
	.string "I wouldn't be surprised if {STR_VAR_3}\n"
	.string "were weeping over this outcome.$"
	.else
	.ifdef GERMAN
	.string "Es unterlag dem {STR_VAR_2} von\n"
	.string "{STR_VAR_1} um Haaresbreite.\p"
	.string "Es ist erschütternd, so kurz vor dem\n"
	.string "Sieg zu scheitern.\p"
	.string "Ich wäre nicht erstaunt, wenn {STR_VAR_3}\n"
	.string "nun über diese Niederlage weint.$"
	.endif
	.endif

ContestLiveUpdates_Text_RepeatedAppeals::
	.ifdef ENGLISH
	.string "It disappointed the JUDGE by\n"
	.string "repeating the same appeals.\p"
	.string "It's an unforgivable error in any\n"
	.string "CONTEST, and the POKéMON paid.\p"
	.string "{STR_VAR_1} should feel guilty for\n"
	.string "this sorry showing.$"
	.else
	.ifdef GERMAN
	.string "Es hat den JUROR enttäuscht, weil es\n"
	.string "eine Attacke zweimal zeigte.\p"
	.string "In einem WETTBEWERB ist das wirklich\n"
	.string "ein unverzeihlicher Fehler, für den das\l"
	.string "POKéMON bezahlt hat.\p"
	.string "{STR_VAR_1} sollte ein schlechtes Gewissen\n"
	.string "haben!$"
	.endif
	.endif

ContestLiveUpdates_Text_ValiantEffortButLost::
	.ifdef ENGLISH
	.string "{STR_VAR_1} turned in a valiant effort,\n"
	.string "but…\p"
	.string "It was all for naught, finishing last.\p"
	.string "{STR_VAR_1} should learn from this loss\n"
	.string "and put the knowledge to good use.$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_1} hat sich zwar tapfer\n"
	.string "geschlagen, aber…\p"
	.string "Es half nichts. Nur der letzte Platz war\n"
	.string "drin.\p"
	.string "{STR_VAR_1} sollte aus dieser Niederlage\n"
	.string "lernen und das Beste daraus machen.$"
	.endif
	.endif

ContestLiveUpdates_Text_Outro::
	.ifdef ENGLISH
	.string "I'd like to end this program with our\n"
	.string "usual farewell to the winners.\p"
	.string "This time, it's {STR_VAR_1} and\n"
	.string "the {STR_VAR_2}!\p"
	.string "MC: Is everyone ready?\n"
	.string "All together now!\p"
	.string "Audience: {STR_VAR_1}! {STR_VAR_2}!\n"
	.string "Congratulations!\l"
	.string "You're the CONTEST winner!$"
	.else
	.ifdef GERMAN
	.string "Jetzt aber sage ich Auf Wiedersehen,\n"
	.string "aber nicht ohne unser übliches Leb wohl\l"
	.string "an unsere Sieger.\p"
	.string "Dieses Mal sind es {STR_VAR_1} und das\n"
	.string "{STR_VAR_2}!\p"
	.string "MC: Seid ihr alle bereit?!?\n"
	.string "Alle zusammen!!!\p"
	.string "Publikum: {STR_VAR_1}! {STR_VAR_2}!\n"
	.string "Herzlichen Glückwunsch!\l"
	.string "Ihr seid die Sieger des WETTBEWERBs!$"
	.endif
	.endif

gTVPokemonBattleUpdateText00::
	.ifdef ENGLISH
	.string "“POKéMON BATTLE UPDATE!”\p"
	.string "Bringing you the results of POKéMON\n"
	.string "battles as they come in!$"
	.else
	.ifdef GERMAN
	.string "“ATEMBERAUBENDE POKéMON-KÄMPFE”\p"
	.string "Wir zeigen euch die Ergebnisse von\n"
	.string "Kämpfen, sobald diese entschieden\l"
	.string "wurden.$"
	.endif
	.endif

gTVPokemonBattleUpdateText01::
	.ifdef ENGLISH
	.string "The TRAINERS {STR_VAR_1} and\n"
	.string "{STR_VAR_2} faced each other in\l"
	.string "a {STR_VAR_3} BATTLE.\p"
	.string "This match ended in victory for\n"
	.string "{STR_VAR_1}!$"
	.else
	.ifdef GERMAN
	.string "Die TRAINER {STR_VAR_1} und {STR_VAR_2}\n"
	.string "traten sich in einem {STR_VAR_3}-\l"
	.string "KAMPF gegenüber.\p"
	.string "{STR_VAR_1} ging als Sieger daraus\n"
	.string "hervor!$"
	.endif
	.endif

gTVPokemonBattleUpdateText02::
	.ifdef ENGLISH
	.string "In the battle, {STR_VAR_1}'s\n"
	.string "{STR_VAR_2} was a formidable force\l"
	.string "using {STR_VAR_3}!$"
	.else
	.ifdef GERMAN
	.string "Das {STR_VAR_2} von {STR_VAR_1} zeigte\n"
	.string "mit seiner Attacke {STR_VAR_3} seine\l"
	.string "beeindruckende Kraft.$"
	.endif
	.endif

gTVPokemonBattleUpdateText03::
	.ifdef ENGLISH
	.string "{STR_VAR_1}'s {STR_VAR_2} had a weak\n"
	.string "showing that really hurt.$"
	.else
	.ifdef GERMAN
	.string "Das {STR_VAR_2} von {STR_VAR_1}\n"
	.string "dagegen zeigte eine schmerzhafte\l"
	.string "Schwäche.$"
	.endif
	.endif

gTVPokemonBattleUpdateText04::
	.ifdef ENGLISH
	.string "Congratulations on your victory,\n"
	.string "{STR_VAR_1}!\p"
	.string "And for the defeated {STR_VAR_2},\n"
	.string "we hope for a better result next time!\p"
	.string "This concludes this episode of\n"
	.string "“POKéMON BATTLE UPDATE!”$"
	.else
	.ifdef GERMAN
	.string "Herzlichen Glückwunsch, {STR_VAR_1}!\p"
	.string "Und {STR_VAR_2} wünschen wir für den\n"
	.string "nächsten Kampf mehr Erfolg!\p"
	.string "Und damit beenden wir\n"
	.string "“ATEMBERAUBENDE POKéMON-KÄMPFE”$"
	.endif
	.endif

gTVPokemonBattleUpdateText05::
	.ifdef ENGLISH
	.string "The teams of TRAINERS {STR_VAR_1} and\n"
	.string "{STR_VAR_2} met in a MULTI BATTLE.\p"
	.string "This match ended in victory for\n"
	.string "{STR_VAR_1}'s team.$"
	.else
	.ifdef GERMAN
	.string "Die Teams der TRAINER {STR_VAR_1} und\n"
	.string "{STR_VAR_2} haben sich in einem MULTI-\l"
	.string "KAMPF gemessen.\p"
	.string "Das Team von {STR_VAR_1} ging als\n"
	.string "Sieger daraus hervor.$"
	.endif
	.endif

gTVPokemonBattleUpdateText06::
	.ifdef ENGLISH
	.string "In the battle, the {STR_VAR_2} on\n"
	.string "{STR_VAR_1}'s team was a formidable\l"
	.string "force using {STR_VAR_3}.$"
	.else
	.ifdef GERMAN
	.string "Das {STR_VAR_2} von {STR_VAR_1} zeigte\n"
	.string "mit seiner Attacke {STR_VAR_3} seine\l"
	.string "beeindruckende Kraft.$"
	.endif
	.endif

gTVPokemonBattleUpdateText07::
	.ifdef ENGLISH
	.string "The weak showing by the {STR_VAR_3}\n"
	.string "on {STR_VAR_2}'s team really hurt.\p"
	.string "Congratulations on your team's\n"
	.string "victory, {STR_VAR_1}!\p"
	.string "As for the defeated {STR_VAR_2}'s team,\n"
	.string "we hope for a better result next time!\p"
	.string "This concludes this episode of\n"
	.string "“POKéMON BATTLE UPDATE!”$"
	.else
	.ifdef GERMAN
	.string "{STR_VAR_3} aus dem Team von\n"
	.string "{STR_VAR_2} zeigte eine schmerzliche\l"
	.string "Schwäche.\p"
	.string "Herzlichen Glückwunsch an dein Team,\n"
	.string "{STR_VAR_1}!\p"
	.string "Und dem Team von {STR_VAR_2} wünschen\n"
	.string "wir, dass es bald gewinnen wird!\p"
	.string "Und damit beenden wir\n"
	.string "“ATEMBERAUBENDE POKéMON-KÄMPFE”$"
	.endif
	.endif

GabbyAndTy_Text_GabbyPreFirstBattle:
	.ifdef ENGLISH
	.string "GABBY: Oh! We've just spotted a tough-\n"
	.string "looking TRAINER here of all places!\p"
	.string "Okay, roll camera!\n"
	.string "Let's get this interview.$"
	.else
	.ifdef GERMAN
	.string "PIA: Oh! Wir haben hier viele stark\n"
	.string "aussehende TRAINER gesehen!\p"
	.string "Okay, Kamera ab!\n"
	.string "Interviewen wir jemanden!$"
	.endif
	.endif

GabbyAndTy_Text_GabbyIntro:
	.ifdef ENGLISH
	.string "GABBY: Oh! You're {PLAYER}! Hi!\n"
	.string "Do you remember us from last time?\p"
	.string "Can you show us how much stronger\n"
	.string "you've become? Okay, cue interview!$"
	.else
	.ifdef GERMAN
	.string "PIA: Oh! Du bist {PLAYER}! Hallo!\n"
	.string "Erinnerst du dich an uns?\p"
	.string "Zeigst du uns, wie stark du geworden\n"
	.string "bist? Okay, das war das Stichwort.$"
	.endif
	.endif

GabbyAndTy_Text_GabbyDefeatFirstTime:
	.ifdef ENGLISH
	.string "GABBY: My eyes didn't lie!\n"
	.string "I did discover an astonishing TRAINER!$"
	.else
	.ifdef GERMAN
	.string "PIA: Mein Gefühl hat nicht getrogen.\n"
	.string "Der TRAINER ist wirklich erstaunlich.$"
	.endif
	.endif

GabbyAndTy_Text_WhoAreYouInterview:
	.ifdef ENGLISH
	.string "GABBY: Awesome! Awesome!\n"
	.string "Who are you?!\p"
	.string "I knew we were onto something wild\n"
	.string "when we spotted you!\p"
	.string "Oh, please let me explain. We travel\n"
	.string "around everywhere interviewing all\l"
	.string "sorts of TRAINERS.\p"
	.string "So, would you give us a bit of your time\n"
	.string "for an interview?$"
	.else
	.ifdef GERMAN
	.string "PIA: Erstaunlich! Erstaunlich!\n"
	.string "Wer bist du?!?\p"
	.string "Ich wusste, wir erleben etwas Außerge-\n"
	.string "wöhnliches, als wir dich gesehen haben.\p"
	.string "Oh, ich schulde dir eine Erklärung. Wir\n"
	.string "reisen durch das Land und führen mit\l"
	.string "TRAINERn Interviews.\p"
	.string "Würdest du uns auch etwas von deiner\n"
	.string "Zeit zur Verfügung stellen?$"
	.endif
	.endif

GabbyAndTy_Text_QuoteFromLastInterview:
	.ifdef ENGLISH
	.string "GABBY: “{STR_VAR_1}!”\p"
	.string "Remember? That's the quote you gave\n"
	.string "us as the battle clincher last time.\p"
	.string "I never, ever forget stuff like that!$"
	.else
	.ifdef GERMAN
	.string "PIA: “{STR_VAR_1}!”\p"
	.string "Erinnerst du dich? Das hast du uns das\n"
	.string "letzte Mal nach einem Kampf gesagt.\p"
	.string "So etwas vergesse ich nie!$"
	.endif
	.endif

GabbyAndTy_Text_YouStompedUsInterviewAgain:
	.ifdef ENGLISH
	.string "The last time we battled, you stomped\n"
	.string "us before we could brace ourselves…\p"
	.string "Anyway, what do you think?\n"
	.string "Do you want to be interviewed again?$"
	.else
	.ifdef GERMAN
	.string "Als wir das letzte Mal kämpften, hast du\n"
	.string "uns in den Boden gerammt, bevor wir\l"
	.string "etwas dagegen tun konnten…\p"
	.string "Und wie sieht es heute aus? Dürfen\n"
	.string "wir dich noch einmal interviewen?$"
	.endif
	.endif

GabbyAndTy_Text_YouThrewABallAtUsInterviewAgain:
	.ifdef ENGLISH
	.string "The last time we battled, didn't you\n"
	.string "throw a POKé BALL at us?\p"
	.string "We were shocked! So we told everyone,\n"
	.string "just everyone, about it!\p"
	.string "Anyway, what do you think?\n"
	.string "Do you want to be interviewed again?$"
	.else
	.ifdef GERMAN
	.string "Hast du bei unserem letzten Kampf\n"
	.string "nicht einen POKéBALL nach uns\l"
	.string "geworfen?\p"
	.string "Wir waren geschockt! Daher haben wir\n"
	.string "das jedem, wirklich jedem, erzählt!\p"
	.string "Was meinst du? Dürfen wir dich noch\n"
	.string "einmal interviewen?$"
	.endif
	.endif

GabbyAndTy_Text_CleverItemSkillsInterviewAgain:
	.ifdef ENGLISH
	.string "The last time we battled, your item\n"
	.string "skills cleverly did us in.\p"
	.string "Anyway, what do you think?\n"
	.string "Do you want to be interviewed again?$"
	.else
	.ifdef GERMAN
	.string "Bei unserem letzten Kampf hast du uns\n"
	.string "mit dem Einsatz der Items geschlagen.\p"
	.string "Was meinst du? Dürfen wir dich noch\n"
	.string "einmal interviewen?$"
	.endif
	.endif

GabbyAndTy_Text_WeLookedRespectableInterviewAgain:
	.ifdef ENGLISH
	.string "The last time we battled, we managed\n"
	.string "to look respectable.\p"
	.string "Anyway, what do you think?\n"
	.string "Do you want to be interviewed again?$"
	.else
	.ifdef GERMAN
	.string "In unserem letzten Kampf haben wir uns\n"
	.string "bemüht, nicht ganz so übel auszusehen.\p"
	.string "Was meinst du? Dürfen wir dich noch\n"
	.string "einmal interviewen?$"
	.endif
	.endif

GabbyAndTy_Text_InterviewAgain:
	.ifdef ENGLISH
	.string "Anyway, what do you think?\n"
	.string "Do you want to be interviewed again?$"
	.else
	.ifdef GERMAN
	.string "Was meinst du? Dürfen wir dich noch\n"
	.string "einmal interviewen?$"
	.endif
	.endif

GabbyAndTy_Text_DescribeYourFeelings:
	.ifdef ENGLISH
	.string "You will?\n"
	.string "Thank you!\p"
	.string "Okay, I need you to describe your\n"
	.string "feelings about our battle, but it\l"
	.string "has to be short and sweet. Go!$"
	.else
	.ifdef GERMAN
	.string "Ja?\n"
	.string "Wunderbar! Danke!\p"
	.string "Okay. Wie würdest du deine Gefühle\n"
	.string "hinsichtlich unseres Kampfes\l"
	.string "beschreiben? Kurz und nett, bitte.$"
	.endif
	.endif

GabbyAndTy_Text_PerfectWellBeSeeingYou:
	.ifdef ENGLISH
	.string "GABBY: Mmm, yeah!\n"
	.string "That's the perfect clincher!\p"
	.string "I get the feeling that this will make\n"
	.string "a great TV show.\p"
	.string "There's a chance that they'll air this\n"
	.string "on TV, so make sure to look for us!\p"
	.string "Okay!\n"
	.string "We'll be seeing you!$"
	.else
	.ifdef GERMAN
	.string "PIA: Mmm, yeah!\n"
	.string "Das ist das perfekte Schlagwort!\p"
	.string "Ich bin überzeugt, dass dies eine groß-\n"
	.string "artige TV-Sendung wäre!\p"
	.string "Vielleicht strahlen sie dies im Fern-\n"
	.string "sehen aus, also achte auf das Programm!\p"
	.string "Okay!\n"
	.string "Man sieht sich!$"
	.endif
	.endif

GabbyAndTy_Text_DontGiveUpKeepingEyeOut:
	.ifdef ENGLISH
	.string "GABBY: Oh…\p"
	.string "Okay, but don't give up!\n"
	.string "We'll be keeping an eye out for you!$"
	.else
	.ifdef GERMAN
	.string "PIA: Oh…\p"
	.string "Okay, aber gib nicht auf!\n"
	.string "Wir werden dich weiter im Auge behalten!$"
	.endif
	.endif

GabbyAndTy_Text_KeepingAnEyeOutForYou:
	.ifdef ENGLISH
	.string "GABBY: We'll be keeping an eye out\n"
	.string "for you!$"
	.else
	.ifdef GERMAN
	.string "PIA: Wir werden dich im Auge behalten!$"
	.endif
	.endif

GabbyAndTy_Text_GabbyNotEnoughMons:
	.ifdef ENGLISH
	.string "GABBY: Is there a strong TRAINER\n"
	.string "anywhere with a lot of POKéMON?$"
	.else
	.ifdef GERMAN
	.string "PIA: Gibt es irgendwo einen starken\n"
	.string "TRAINER mit vielen POKéMON?$"
	.endif
	.endif

GabbyAndTy_Text_GiveUsAnInterviewThisTime:
	.ifdef ENGLISH
	.string "GABBY: Wow, you are something!\p"
	.string "You've gotten a lot stronger--a lot--\n"
	.string "since we last battled.\p"
	.string "We were right about you when we\n"
	.string "spotted you as a hot TRAINER.\p"
	.string "So, anyway, what do you think?\n"
	.string "Are you willing to give us an interview\l"
	.string "this time?$"
	.else
	.ifdef GERMAN
	.string "PIA: Wow, das war was!\p"
	.string "Seit unserem letzten Kampf bist du\n"
	.string "stärker geworden - viel stärker.\p"
	.string "Unser Gefühl, du würdest ein heißer\n"
	.string "TRAINER werden, hat uns Recht gegeben.\p"
	.string "Was meinst du? Dürfen wir dich noch\n"
	.string "einmal interviewen?$"
	.endif
	.endif

GabbyAndTy_Text_GabbyDefeat:
	.ifdef ENGLISH
	.string "GABBY: That was an intense battle!\n"
	.string "Did you get all that on camera?$"
	.else
	.ifdef GERMAN
	.string "PIA: Das war aber ein intensiver\n"
	.string "Kampf! Hast du alles aufgezeichnet?!?$"
	.endif
	.endif

GabbyAndTy_Text_TyPreFirstBattle:
	.ifdef ENGLISH
	.string "TY: Hey, lookie here! A tough-looking\n"
	.string "TRAINER here, of all places!\l"
	.string "Camera's rolling!$"
	.else
	.ifdef GERMAN
	.string "UDO: Hey, guck mal! Ein stark\n"
	.string "aussehender TRAINER! Und das hier\l"
	.string "an diesem Ort! Kamera ab!$"
	.endif
	.endif

GabbyAndTy_Text_TyIntro:
	.ifdef ENGLISH
	.string "TY: Hey, lookie here!\n"
	.string "I remember you!\p"
	.string "I'll get this battle all on this\n"
	.string "here camera!$"
	.else
	.ifdef GERMAN
	.string "UDO: Da schau her!\n"
	.string "Ich erinnere mich an dich!\p"
	.string "Ich werde den ganzen Kampf mit der\n"
	.string "Kamera aufnehmen!$"
	.endif
	.endif

GabbyAndTy_Text_TyPostBattle:
	.ifdef ENGLISH
	.string "TY: You're a natural!\n"
	.string "Got me some prime footage right here!$"
	.else
	.ifdef GERMAN
	.string "UDO: Du bist ein Naturtalent!\n"
	.string "Du gibst mir erstklassiges Bildmaterial!$"
	.endif
	.endif

GabbyAndTy_Text_TyNotEnoughMons:
	.ifdef ENGLISH
	.string "TY: Do you only have the one POKéMON\n"
	.string "and that's it?\p"
	.string "If you had more POKéMON, it'd make for\n"
	.string "better footage, but…$"
	.else
	.ifdef GERMAN
	.string "UDO: Du hast nur ein POKéMON?\n"
	.string "Mehr nicht?\p"
	.string "Wenn du mehr POKéMON hättest, wäre\n"
	.string "das Bildmaterial viel, viel besser!$"
	.endif
	.endif

GabbyAndTy_Text_TyDefeatFirstTime:
	.ifdef ENGLISH
	.string "TY: Yep, we sure spotted a hot TRAINER.\n"
	.string "This is a huge scoop for us!$"
	.else
	.ifdef GERMAN
	.string "UDO: Wir haben tatsächlich einen\n"
	.string "starken TRAINER entdeckt.\l"
	.string "Das ist unser Durchbruch.$"
	.endif
	.endif

GabbyAndTy_Text_TyDefeat:
	.ifdef ENGLISH
	.string "TY: Yep, I got it all.\n"
	.string "That whole battle's on camera.$"
	.else
	.ifdef GERMAN
	.string "UDO: Ja, alles im Kasten!\n"
	.string "Der ganze Kampf ist auf Band!$"
	.endif
	.endif

gTVInSearchOfTrainersText00::
	.ifdef ENGLISH
	.string "IN SEARCH OF TRAINERS…\p"
	.string "GABBY: Hi! Today I'm visiting an area\n"
	.string "near {STR_VAR_1}.\p"
	.string "We're trying to spot some up-and-\n"
	.string "coming new talent in the field.\p"
	.string "Today, we turned our lens on the\n"
	.string "TRAINER {PLAYER}.\p"
	.string "There's something about this TRAINER\n"
	.string "that piqued our interest.$"
	.else
	.ifdef GERMAN
	.string "AUF DER SUCHE NACH TRAINERN…\p"
	.string "PIA: Hallo! Heute besuche ich ein Ge-\n"
	.string "biet in der Nähe von {STR_VAR_1}.\p"
	.string "Wir versuchen, ein neues, großes\n"
	.string "Talent zu finden.\p"
	.string "Unsere Kamera ruht daher auf dem\n"
	.string "TRAINER {PLAYER}.\p"
	.string "Etwas an diesem TRAINER hat unser\n"
	.string "Interesse geweckt…$"
	.endif
	.endif

gTVInSearchOfTrainersText01::
	.ifdef ENGLISH
	.string "We've battled {PLAYER} before, but we\n"
	.string "can attest that the TRAINER has most\l"
	.string "definitely improved from before.\p"
	.string "I knew we were onto someone special\n"
	.string "when we spotted this TRAINER!$"
	.else
	.ifdef GERMAN
	.string "Wir sind schon früher gegen {PLAYER}\n"
	.string "angetreten, und wir versichern, dass\l"
	.string "der TRAINER viel stärker geworden ist!\p"
	.string "Ich wusste sofort, dass wir hier einen\n"
	.string "ganz besonderen TRAINER vor uns haben.$"
	.endif
	.endif

gTVInSearchOfTrainersText02::
	.ifdef ENGLISH
	.string "The best way to determine how strong\n"
	.string "a TRAINER is…\p"
	.string "Well, the fastest way is to battle.\n"
	.string "And so we began our investigation!\p"
	.string "… …\p"
	.string "That's how we ended up in battle\n"
	.string "with {PLAYER}.\p"
	.string "In a dominating performance, we were\n"
	.string "flattened, rolled up, and tossed aside!\p"
	.string "{PLAYER} is ruthlessly strong…\p"
	.string "Here's our impressions after having\n"
	.string "battled our featured TRAINER.$"
	.else
	.ifdef GERMAN
	.string "Die beste Art, das Können eines\n"
	.string "TRAINERs festzustellen, ist…\p"
	.string "gegen ihn zu kämpfen.\n"
	.string "Und das haben wir gemacht.\p"
	.string "… …\p"
	.string "Und so endete schließlich der Kampf\n"
	.string "gegen {PLAYER}.\p"
	.string "Seine dominierende Vorstellung schlug\n"
	.string "uns vernichtend, zerknüllte uns und\l"
	.string "warf uns weg.\p"
	.string "{PLAYER} ist einfach unglaublich stark…\p"
	.string "Gehen wir etwas näher auf den Kampf\n"
	.string "ein.$"
	.endif
	.endif

gTVInSearchOfTrainersText03::
	.ifdef ENGLISH
	.string "The combination of {STR_VAR_1} and\n"
	.string "{STR_VAR_3} was divine!\p"
	.string "The sight of them--{STR_VAR_1} and\n"
	.string "{STR_VAR_3}--selflessly supporting\l"
	.string "each other in the thick of battle…\p"
	.string "It was a marvelous sight to behold!\p"
	.string "{STR_VAR_2} was the move the TRAINER\n"
	.string "used last in our battle.\p"
	.string "The move {STR_VAR_2} is {STR_VAR_1}\n"
	.string "and {STR_VAR_3}'s sign of friendship!$"
	.else
	.ifdef GERMAN
	.string "Die Kombination von {STR_VAR_1} und\n"
	.string "{STR_VAR_3} war einfach göttlich!\p"
	.string "Schon die Ausstrahlung der beiden ließ\n"
	.string "erkennen, dass sie sich gegenseitig un-\l"
	.string "eingeschränkt unterstützen würden.\p"
	.string "Einfach eine unglaubliche Atmosphäre!\p"
	.string "Der TRAINER setzte als letzte Attacke\n"
	.string "{STR_VAR_2} ein.\p"
	.string "Die Attacke {STR_VAR_2} ist das\n"
	.string "Zeichen der Freundschaft zwischen\l"
	.string "{STR_VAR_1} und {STR_VAR_3}.$"
	.endif
	.endif

gTVInSearchOfTrainersText04::
	.ifdef ENGLISH
	.string "…I lost confidence in myself as\n"
	.string "a result of our encounter.\p"
	.string "We were beaten before we could launch\n"
	.string "a single attack.\l"
	.string "Ohhh… Snivel…\p"
	.string "In spite of that, {PLAYER}'s battles\n"
	.string "are worth seeing.\p"
	.string "I recommend confident TRAINERS to\n"
	.string "challenge {PLAYER}.$"
	.else
	.ifdef GERMAN
	.string "So geht mein ganzes Selbstbewusstsein\n"
	.string "dahin… Die Folge unserer Entdeckung.\p"
	.string "Wir wurden geschlagen, bevor wir\n"
	.string "überhaupt eine einzige Attacke ein-\l"
	.string "setzen konnten. Oooh… Schnüff…\p"
	.string "Allein das macht die Kämpfe von\n"
	.string "{PLAYER} schon sehenswert.\p"
	.string "Ich fordere mutige TRAINER auf, sich\n"
	.string "mit {PLAYER} zu messen!$"
	.endif
	.endif

gTVInSearchOfTrainersText05::
	.ifdef ENGLISH
	.string "There's only one thing to be said.\n"
	.string "Don't you dare throw a POKé BALL during\l"
	.string "a TRAINER battle!\p"
	.string "{PLAYER} is certainly strong, but has\n"
	.string "no clue about the basic rules.\p"
	.string "To our TV audience, I have a request.\p"
	.string "If you see {PLAYER}, please caution\n"
	.string "the TRAINER!$"
	.else
	.ifdef GERMAN
	.string "Dazu gibt es nur eines zu sagen.\n"
	.string "Wage es nicht, während eines Kampfes\l"
	.string "einen POKéBALL zu werfen!\p"
	.string "{PLAYER} mag ein starker Kämpfer sein,\n"
	.string "aber die Regeln kennt er nicht.\p"
	.string "Ich gebe unseren Zuschauern\n"
	.string "einen Tipp.\p"
	.string "Wenn ihr {PLAYER} seht, dann weist den\n"
	.string "TRAINER zurecht!$"
	.endif
	.endif

gTVInSearchOfTrainersText06::
	.ifdef ENGLISH
	.string "{PLAYER} is adept at reading the\n"
	.string "opponent's actions.\p"
	.string "The timing of item usage was remarkably\n"
	.string "effective!$"
	.else
	.ifdef GERMAN
	.string "{PLAYER} hat ein Talent dafür, das Vor-\n"
	.string "gehen seines Gegners vorherzusehen.\p"
	.string "Das Item wurde erstaunlicherweise \n"
	.string "genau zum richtigen Zeitpunkt benutzt!$"
	.endif
	.endif

gTVInSearchOfTrainersText07::
	.ifdef ENGLISH
	.string "Honestly speaking, I thought that\n"
	.string "I might even be pretty good.\p"
	.string "While we did end up losing, we did have\n"
	.string "a hotly contested battle.\p"
	.string "But if you're struggling against me,\n"
	.string "you have a ways to go, {PLAYER}!$"
	.else
	.ifdef GERMAN
	.string "Ehrlich gesagt, bin ich davon ausge-\n"
	.string "gangen, dass ich sehr gut bin.\p"
	.string "Auch wenn wir verloren haben,\n"
	.string "war es ein heißer Kampf!\p"
	.string "Wenn du es mit uns aufnehmen willst,\n"
	.string "{PLAYER}, musst du noch viel trainieren!$"
	.endif
	.endif

gTVInSearchOfTrainersText08::
	.ifdef ENGLISH
	.string "After our battle, we asked {PLAYER} for\n"
	.string "a succinct summary.\p"
	.string "The TRAINER replied, “{STR_VAR_1}.”\p"
	.string "{PLAYER}'s POKéMON {STR_VAR_2} and\n"
	.string "{STR_VAR_3}…\l"
	.string "And “{STR_VAR_1}”…\p"
	.string "Mmm! That's deep! There's deep\n"
	.string "significance behind that quote!\p"
	.string "It's no surprise--a good TRAINER has\n"
	.string "good things to say.\p"
	.string "That's all for today!\n"
	.string "See you again on our next broadcast!$"
	.else
	.ifdef GERMAN
	.string "Nach dem Kampf baten wir {PLAYER}\n"
	.string "um eine kurze Stellungnahme.\p"
	.string "Der TRAINER sagte: “{STR_VAR_1}”.\p"
	.string "Die POKéMON {STR_VAR_2} und\n"
	.string "{STR_VAR_3} von {PLAYER}…\l"
	.string "Und “{STR_VAR_1}”…\p"
	.string "Mmh! Sehr tiefsinnig! Da liegt ein\n"
	.string "tieferer Sinn in dieser Aussage!\p"
	.string "Kein Wunder! Ein bedeutender TRAINER\n"
	.string "wird auch bedeutende Worte sagen!\p"
	.string "Das war’s für heute!\n"
	.string "Bis zur nächsten Sendung!$"
	.endif
	.endif

ContestLadyShow_Text_Intro::
	.ifdef ENGLISH
	.string "“POKéMON CONTEST LIVE UPDATES!”\p"
	.string "MC: Sorry to interrupt the regular\n"
	.string "programming, and thanks for joining us!\p"
	.string "We bring you this live from\n"
	.string "the scene of a just-completed\l"
	.string "{STR_VAR_1}!\p"
	.string "Spectators: ?!!!!\p"
	.string "MC: Oh! It looks like the CONTEST\n"
	.string "participants are headed this way!\p"
	.string "I'll try to get an impromptu interview\n"
	.string "for you folks at home!\p"
	.string "Spectators: ?!!!!\n"
	.string "?!!!!$"
	.else
	.ifdef GERMAN
	.string "“LIVE VON DEN POKéMON- WETTBEWERBen”\p"
	.string "MC: Wir unterbrechen das aktuelle\n"
	.string "Programm und berichten live von dem\l"
	.string "gerade beendeten {STR_VAR_1}!\p"
	.string "Zuschauer: ?!!\p"
	.string "MC: Oh! Die Teilnehmer des WETTBEWERBs\n"
	.string "kommen gerade hier vorbei!\p"
	.string "Ich versuche, spontan ein Interview\n"
	.string "für euch zu Hause zu arrangieren.\p"
	.string "Zuschauer: ?!!\n"
	.string "?!!$"
	.endif
	.endif

ContestLadyShow_Text_Won::
	.ifdef ENGLISH
	.string "MC: Excuse me!\n"
	.string "Thanks for joining us on live TV!\p"
	.string "May I congratulate you on your win?\p"
	.string "What was the key factor in today's\n"
	.string "stunning victory?\p"
	.string "BEAUTY: We gave it our best effort\n"
	.string "today, my {STR_VAR_2} and I!\p"
	.string "But I'm sure we wouldn't have made it\n"
	.string "if it weren't for all the help we\l"
	.string "received leading up to the CONTEST!\p"
	.string "MC: Do you have a special someone\n"
	.string "with whom you'd like to share your joy?\l"
	.string "Let's hear it live!\p"
	.string "BEAUTY: Hey, out there!\p"
	.string "{STR_VAR_3}! Are you watching?\n"
	.string "We did it!\l"
	.string "Thank you!$"
	.else
	.ifdef GERMAN
	.string "MC: Entschuldige bitte!\n"
	.string "Danke, dass du dich für meine Sendung\l"
	.string "zur Verfügung stellst!\p"
	.string "Darf ich dir zu deinem Sieg gratulieren?\p"
	.string "Was war das ausschlaggebende Moment\n"
	.string "für deinen heutigen atemberaubenden\l"
	.string "Sieg?\p"
	.string "SCHÖNHEIT: Wir haben heute einfach\n"
	.string "unser Bestes gegeben, mein {STR_VAR_2}\l"
	.string "und ich!\p"
	.string "Aber wir hätten es ohne die\n"
	.string "Unterstützung, die wir vor und im\p"
	.string "WETTBEWERB erhalten haben, nicht\n"
	.string "geschafft!\p"
	.string "MC: Gibt es jemand Besonderen, mit dem\n"
	.string "du deine Freude teilen möchtest?\p"
	.string "SCHÖNHEIT: Hey, da draußen!\p"
	.string "{STR_VAR_3}! Schaust du gerade zu?\n"
	.string "Wir haben es geschafft!!!\l"
	.string "Vielen Dank!$"
	.endif
	.endif

ContestLadyShow_Text_Lost::
	.ifdef ENGLISH
	.string "MC: Excuse me!\n"
	.string "Thanks for joining us on live TV!\p"
	.string "You must be disappointed by that turn\n"
	.string "of events. Do you have any comments?\p"
	.string "BEAUTY: It's heartbreaking…\n"
	.string "My {STR_VAR_2} and I, we did our best…\p"
	.string "But I feel like I've let down everyone\n"
	.string "who has supported us through this.\p"
	.string "MC: I hate to say it, but the POKéMON's\n"
	.string "coloration is a little wanting.\p"
	.string "BEAUTY: {STR_VAR_3}, I'm so sorry…\n"
	.string "I'll do better next time, I swear…\l"
	.string "…Sniff… Waaaaah!\p"
	.string "Spectators: See that?\n"
	.string "The poor girl!\p"
	.string "MC: Uh… Uh-oh…\p"
	.string "Uh… That's all the time we have today!\n"
	.string "Thanks for tuning in!$"
	.else
	.ifdef GERMAN
	.string "MC: Entschuldige bitte!\n"
	.string "Danke, dass du dich für meine Sendung\l"
	.string "zur Verfügung stellst!\p"
	.string "Du bist bestimmt enttäuscht über den\n"
	.string "Ausgang. Willst du uns ein paar Worte\l"
	.string "dazu sagen?\p"
	.string "SCHÖNHEIT: Es ist herzzerreißend…\n"
	.string "Mein {STR_VAR_2} und ich, wir haben\l"
	.string "unser Bestes gegeben…\p"
	.string "Aber ich habe das Gefühl, jeden, der uns\n"
	.string "bis hierher unterstützt hat,\l"
	.string "enttäuscht zu haben.\p"
	.string "MC: Ich hasse es, das zu sagen, aber die\n"
	.string "Farben des POKéMON wirken ein bisschen\l"
	.string "deplatziert.\p"
	.string "SCHÖNHEIT: {STR_VAR_3}, es tut mir so\n"
	.string "Leid… Nächstes Mal werde ich besser\l"
	.string "abschneiden, das schwöre ich…\p"
	.string "Schluchz… \p"
	.string "Publikum: Seht mal! Das arme Mädchen!\p"
	.string "MC: Äh… Oh oh…\p"
	.string "Äh… Das war’s für heute!\n"
	.string "Vielen Dank für’s Zuschauen!$"
	.endif
	.endif

ContestLadyShow_Text_LostBadly::
	.ifdef ENGLISH
	.string "MC: Excuse me!\n"
	.string "Thanks for joining us on live TV!\p"
	.string "How did your CONTEST appearance go?\p"
	.string "BEAUTY: Nothing went right…\n"
	.string "For some reason, my {STR_VAR_2}\l"
	.string "couldn't attract any popularity.\p"
	.string "MC: I hate to say it, but the POKéMON's\n"
	.string "coloration is a little wanting.\p"
	.string "BEAUTY: … … … … … …\n"
	.string "…Sniff… Waaaaah!\p"
	.string "Spectators: See that?\n"
	.string "The poor girl!\p"
	.string "MC: Uh… Uh-oh…\p"
	.string "Uh… That's all the time we have today!\n"
	.string "Thanks for tuning in!$"
	.else
	.ifdef GERMAN
	.string "MC: Entschuldige!\n"
	.string "Vielen Dank, dass ihr an meiner Sendung\l"
	.string "teilnehmt.\p"
	.string "Wie lief der WETTBEWERB für dich?\p"
	.string "SCHÖNHEIT: Nichts lief so wie es sein\n"
	.string "sollte… Aus irgendeinem Grund konnte\p"
	.string "mein {STR_VAR_2} das Publikum nicht\n"
	.string "begeistern.\p"
	.string "MC: Ich hasse es, das zu sagen, aber die\n"
	.string "Farbe deines POKéMON wirkt etwas\l"
	.string "deplatziert.\p"
	.string "Schönheit: … … … …\n"
	.string "… …\l"
	.string "Schluchz… Waaaahaaaaa…\p"
	.string "Publikum: Seht mal! Das arme Mädchen!\p"
	.string "MC: Äh… Oh oh…\p"
	.string "Äh… Das war’s von uns für heute!\n"
	.string "Vielen Dank für’s Einschalten.$"
	.endif
	.endif
