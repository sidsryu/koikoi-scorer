set(scorer_src
	koikoi-scorer.cpp	
	begining-hands.cpp	
	point-pile.cpp
	point-rules.cpp
	card-functor.cpp
	monthly-card.cpp
	score-table.cpp
	scoring-hand-calculator.cpp
		
	point-pile.h
	point-rules.h
	card-functor.h
	monthly-card.h
	score-table.h
	scoring-hand-calculator.h
)

set(scorer_inc
	koikoi-scorer.h
	begining-hands.h
	card-define.h		
	rule-define.h
	month-define.h
	scoring-define.h
	score-report.h
)

add_library(koikoi-scorer STATIC ${scorer_src} ${scorer_inc})
install(FILES ${scorer_inc} DESTINATION include)
install(TARGETS koikoi-scorer DESTINATION lib)
