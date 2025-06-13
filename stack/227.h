//
// Created by QinJM on 2023/10/30.
//

#ifndef LEETCODE_227_H
#define LEETCODE_227_H
#include <string>
#include <stack>
#include <vector>
using namespace std;
class Solution {
private:
    enum TokenType{
        NUMBER,
        PLUS,
        MINUS,
        MUL,
        DIV,
        LEFT_PAREN,
        RIGHT_PAREN
    };

    struct Token{
        TokenType type;
        int value;
        explicit Token(TokenType type) : type(type), value(0) {}
        explicit Token(int value) : type(NUMBER), value(value) {}
    };

    class Scanner{
    private:
        string source;
        int current = 0;

        char advance(){
            return source.at(current++);
        }

        char peek(){
            return source.at(current);
        }

        char previous(){
            return source.at(current-1);
        }

        bool isAtEnd(){
            return current >= source.size();
        }

        int number(){
            int val = previous() - '0';
            if (isAtEnd()) return val;
            int next = peek() - '0';
            while(0 <= next && next <= 9){
                val = 10 * val + next;
                advance();
                if(isAtEnd()) return val;
                next = peek() - '0';
            }
            return val;
        };

    public:
        explicit Scanner(string& s) : source(s) {}

        vector<Token>* scan(){
            vector<Token>* tokens = new vector<Token>();
            while(!isAtEnd()){
                char c = advance();
                switch (c) {
                    case '(':
                        tokens->emplace_back(LEFT_PAREN);
                        break;
                    case ')':
                        tokens->emplace_back(RIGHT_PAREN);
                        break;
                    case '+':
                        tokens->emplace_back(PLUS);
                        break;
                    case '-':
                        tokens->emplace_back(MINUS);
                        break;
                    case '*':
                        tokens->emplace_back(MUL);
                        break;
                    case '/':
                        tokens->emplace_back(DIV);
                        break;
                    case ' ':
                        break;
                    default:
                        tokens->emplace_back(number());
                        break;
                }
            }
            return tokens;
        }
    };

    class Expr{
    public:
        virtual int getValue() = 0;
    };

    class LiteralExpr : public Expr {
    private:
        int value;
    public:
        explicit LiteralExpr(int value) : value(value) {}
        int getValue() override { return value;}
    };

    class GroupingExpr : public Expr {
    private:
        Expr* subExpr;
    public:
        explicit GroupingExpr(Expr* e) : subExpr(e) {}
        int getValue() override { return subExpr->getValue();}
    };

    class UnaryExpr : public Expr {
    private:
        TokenType oper;
        Expr* subExpr;
    public:
        UnaryExpr(TokenType o, Expr* expr) : oper(o), subExpr(expr) {}
        int getValue() override {
            int sub = subExpr->getValue();
            switch (oper) {
                case MINUS:
                    return -sub;
                default:
                    return 0;
            }
        }
    };

    class BinaryExpr : public Expr {
    private:
        Expr* leftExpr;
        TokenType oper;
        Expr* rightExpr;
    public:
        BinaryExpr(Expr* l, TokenType o, Expr* r) : leftExpr(l), oper(o), rightExpr(r) {}
        int getValue() override {
            int left_val = leftExpr->getValue();
            int right_val = rightExpr->getValue();

            switch (oper) {
                case PLUS:
                    return left_val + right_val;
                case MINUS:
                    return left_val - right_val;
                case MUL:
                    return left_val * right_val;
                case DIV:
                    return left_val / right_val;
                default:
                    return 0;
            }
        };
    };

    class Parser{
    private:
        int current = 0;
        vector<Token>* tokens;

    public:
        explicit Parser(vector<Token>* tokens) : tokens(tokens) {}
        Expr* parse(){
            return Ast();
        }

        Expr* Ast(){
            return term();
        }

        Expr* term() {
            Expr* expr = factor();
            while (match({PLUS, MINUS})){
                TokenType oper = advance().type;
                Expr* right = factor();
                expr = new BinaryExpr(expr, oper, right);
            }
            return expr;
        }

        Expr* factor() {
            Expr* expr = unary();
            while (match({MUL, DIV})){
                TokenType oper = advance().type;
                Expr* right = unary();
                expr = new BinaryExpr(expr, oper, right);
            }
            return expr;
        }

        Expr* unary() {
            if(match({MINUS})){
                TokenType oper = advance().type;
                Expr* right = primary();
                return new UnaryExpr(oper, right);
            }

            return primary();
        }

        Expr* primary() {
            Token t = advance();
            Expr *ret;
            switch (t.type) {
                case NUMBER:
                    ret = new  LiteralExpr(t.value);
                    break;
                case LEFT_PAREN:
                    ret = new GroupingExpr(Ast());
                    consume(RIGHT_PAREN);
                    break;
                default:
                    ret = nullptr;
            }
            return ret;
        }

        bool match(initializer_list<TokenType> types){
            if(isAtEnd()) return false;
            Token t = peek();
            for(auto type : types){
                if( t.type == type) return true;
            }
            return false;
        }

        Token advance(){
            return tokens->at(current++);
        }

        Token peek(){
            return tokens->at(current);
        }

        bool isAtEnd() {
            return current >= tokens->size();
        }

        void consume(TokenType t){
            advance();
        }
    };

public:
    int calculate(string s){
        Scanner* scanner = new Scanner(s);
        vector<Token> *tokens = scanner->scan();
        delete scanner;
        Parser* parser = new Parser(tokens);
        Expr* Ast = parser->parse();
        delete parser;
        return Ast->getValue();
    }
};
#endif //LEETCODE_227_H
