CXX      = c++
CXXFLAGS = -Wextra -Wall -Werror -std=c++98 -pedantic
LDFLAGS  = -g -fsanitize=address

TARGET   = btc
SOURCES  = BitcoinExchange.cpp main.cpp
OBJDIR   = obj
OBJECTS  = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))
DEPS     = $(OBJECTS:.o=.d)

RM       = rm -f

GREEN    = \033[0;32m
RESET    = \033[0m

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CXX) $(LDFLAGS) $^ -o $@
	@echo "$(GREEN)Compiled $(TARGET) successfully.$(RESET)"

-include $(DEPS)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@$(RM) $(OBJECTS) $(DEPS)
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)Cleaned object files, dependencies, and obj directory.$(RESET)"

fclean: clean
	@$(RM) $(TARGET)
	@echo "$(GREEN)Removed executable $(TARGET).$(RESET)"


run1: $(TARGET)
	@./$(TARGET) inputSubject.txt

run2: $(TARGET)
	@./$(TARGET) input.txt

#file doesnt exist
run3 : $(TARGET)
	@./$(TARGET) input2.txt

re: fclean all

.PHONY: all clean fclean re