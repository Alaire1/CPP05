CXX      = g++
CXXFLAGS = -Wextra -Wall -Werror -std=c++98 -pedantic
LDFLAGS  = -g -fsanitize=address

TARGET   = bureaucrats
SOURCES  = Bureaucrat.cpp main.cpp
OBJECTS  = $(SOURCES:.cpp=.o)
DEPS     = $(OBJECTS:.o=.d)

RM       = rm -f

GREEN    = \033[0;32m
RESET    = \033[0m

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@
	@echo "$(GREEN)Compiled $(TARGET) successfully.$(RESET)"


-include $(DEPS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(DEPS)
	@echo "$(GREEN)Cleaned object files and dependencies.$(RESET)"

fclean: clean
	$(RM) $(TARGET)
	@echo "$(GREEN)Removed executable $(TARGET).$(RESET)"

re: fclean all

.PHONY: all clean fclean re