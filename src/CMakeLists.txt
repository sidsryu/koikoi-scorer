set(scorer_src
	koikoi-scorer.cpp
	card-functor.cpp
)

set(scorer_inc
	card-define.h
	card-functor.h
	koikoi-scorer.h
)

add_library(koikoi-scorer STATIC ${scorer_src} ${scorer_inc})
install(FILES ${scorer_inc} DESTINATION include)
install(TARGETS koikoi-scorer DESTINATION lib)
