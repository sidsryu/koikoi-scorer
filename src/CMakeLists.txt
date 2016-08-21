set(scorer_src
	koikoi-scorer.cpp	
	card-functor.cpp	
	begining-hands.cpp
)

set(scorer_inc
	koikoi-scorer.h
	card-define.h
	card-functor.h	
	begining-hands.h
)

add_library(koikoi-scorer STATIC ${scorer_src} ${scorer_inc})
install(FILES ${scorer_inc} DESTINATION include)
install(TARGETS koikoi-scorer DESTINATION lib)
