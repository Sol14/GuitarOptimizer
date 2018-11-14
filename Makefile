.PHONY: clean All

All:
	@echo "----------Building project:[ GuitarOptimizer - Debug ]----------"
	@"$(MAKE)" -f  "GuitarOptimizer.mk"
clean:
	@echo "----------Cleaning project:[ GuitarOptimizer - Debug ]----------"
	@"$(MAKE)" -f  "GuitarOptimizer.mk" clean
