
#include "./../Lexer/Lexer.cpp"
#include "./../Ast/Ast.cpp"

static int CurrTok;
static int getNextTok()
{
    return CurrTok = gettok();
}

std::unique_ptr<ExprAST> LogError(const char *Str)
{
    fprintf(stderr, "Error: %s\n", Str);
    return nullptr;
}

std::unique_ptr<PrototypeAST> LogErrorP(const char *Str)
{
    LogError(Str);
    return nullptr;
}

std::unique_ptr<ExprAST> ParseNumberToken()
{
    auto Result = std::make_unique<NumberExprAST>(NumVal);
    getNextTok();
    return std::move(Result);
}

std::unique_ptr<ExprAST> ParseParenExpr() {
    getNextTok();
    auto V = ParseExpression();
    if(!V)
        return nullptr;
    if(CurrTok != ')')
        return LogError("expected ')'");
    getNextTok();
    return V;
}