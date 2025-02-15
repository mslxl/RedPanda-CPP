/*
 * Copyright (C) 2020-2022 Roy Qu (royqh1979@gmail.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef SYNEDITGLSLHIGHLIGHTER_H
#define SYNEDITGLSLHIGHLIGHTER_H
#include "base.h"
#include <QSet>

namespace QSynedit {

class GLSLHighlighter: public Highlighter
{
    enum TokenId {
        Asm = 1,
        Comment,
        Directive,
        Identifier,
        Key,
        Null,
        Number,
        Space,
        String,
        StringEscapeSeq,
        Symbol,
        Unknown,
        Char,
        Float,
        Hex,
        HexFloat,
        Octal,
        RawString
    };

    enum class ExtTokenId {
        Add, AddAssign, And, AndAssign, Arrow, Assign,
        BitComplement, BraceClose, BraceOpen, Colon, Comma,
        Decrement, Divide, DivideAssign, Ellipse, GreaterThan,
        GreaterThanEqual, IncOr, IncOrAssign, Increment, LessThan,
        LessThanEqual, LogAnd, LogComplement, LogEqual, LogOr,
        Mod, ModAssign, MultiplyAssign, NotEqual, Point, PointerToMemberOfObject,
        PointerToMemberOfPointer,Question,
        RoundClose, RoundOpen, ScopeResolution, SemiColon, ShiftLeft,
        ShiftLeftAssign, ShiftRight, ShiftRightAssign, SquareClose,
        SquareOpen, Star, Subtract, SubtractAssign, Xor,
        XorAssign
    };

    enum RangeState {
        rsUnknown, rsAnsiC, rsAnsiCAsm, rsAnsiCAsmBlock, rsAsm,
        rsAsmBlock, rsDirective, rsDirectiveComment, rsString,
        rsMultiLineString, rsMultiLineDirective, rsCppComment,
        rsStringEscapeSeq, rsMultiLineStringEscapeSeq,
        rsRawString, rsSpace,rsRawStringEscaping,rsRawStringNotEscaping,rsChar,
        rsCppCommentEnded
    };

public:
    explicit GLSLHighlighter();

    PHighlighterAttribute asmAttribute() const;

    PHighlighterAttribute preprocessorAttribute() const;

    PHighlighterAttribute invalidAttribute() const;

    PHighlighterAttribute numberAttribute() const;

    PHighlighterAttribute floatAttribute() const;

    PHighlighterAttribute hexAttribute() const;

    PHighlighterAttribute octAttribute() const;

    PHighlighterAttribute stringEscapeSequenceAttribute() const;

    PHighlighterAttribute charAttribute() const;

    PHighlighterAttribute variableAttribute() const;

    PHighlighterAttribute functionAttribute() const;

    PHighlighterAttribute classAttribute() const;

    PHighlighterAttribute globalVarAttribute() const;

    PHighlighterAttribute localVarAttribute() const;

    static const QSet<QString> Keywords;

    ExtTokenId getExtTokenId();
    TokenKind getTokenId();
private:
    void andSymbolProc();
    void ansiCppProc();
    void ansiCProc();
    void asciiCharProc();
    void atSymbolProc();
    void braceCloseProc();
    void braceOpenProc();
    void colonProc();
    void commaProc();
    void directiveProc();
    void directiveEndProc();
    void equalProc();
    void greaterProc();
    void identProc();
    void lowerProc();
    void minusProc();
    void modSymbolProc();
    void notSymbolProc();
    void nullProc();
    void numberProc();
    void orSymbolProc();
    void plusProc();
    void pointProc();
    void questionProc();
    void rawStringProc();
    void roundCloseProc();
    void roundOpenProc();
    void semiColonProc();
    void slashProc();
    void spaceProc();
    void squareCloseProc();
    void squareOpenProc();
    void starProc();
    void stringEndProc();
    void stringEscapeSeqProc();
    void stringProc();
    void stringStartProc();
    void tildeProc();
    void unknownProc();
    void xorSymbolProc();
    void processChar();
    void popIndents(int indentType);
    void pushIndents(int indentType);

private:
    bool mAsmStart;
    HighlighterState mRange;
//    SynRangeState mSpaceRange;
    QString mLineString;
    QChar* mLine;
    int mLineSize;
    int mRun;
    int mStringLen;
    int mToIdent;
    int mTokenPos;
    int mTokenId;
    ExtTokenId mExtTokenId;
    int mLineNumber;
    int mLeftBraces;
    int mRightBraces;

    PHighlighterAttribute mAsmAttribute;
    PHighlighterAttribute mPreprocessorAttribute;
    PHighlighterAttribute mInvalidAttribute;
    PHighlighterAttribute mNumberAttribute;
    PHighlighterAttribute mFloatAttribute;
    PHighlighterAttribute mHexAttribute;
    PHighlighterAttribute mOctAttribute;
    PHighlighterAttribute mStringEscapeSequenceAttribute;
    PHighlighterAttribute mCharAttribute;
    PHighlighterAttribute mVariableAttribute;
    PHighlighterAttribute mFunctionAttribute;
    PHighlighterAttribute mClassAttribute;
    PHighlighterAttribute mGlobalVarAttribute;
    PHighlighterAttribute mLocalVarAttribute;

    // SynHighligterBase interface
public:
    bool getTokenFinished() const override;
    bool isLastLineCommentNotFinished(int state) const override;
    bool isLastLineStringNotFinished(int state) const override;
    bool eol() const override;
    QString getToken() const override;
    PHighlighterAttribute getTokenAttribute() const override;
    TokenKind getTokenKind() override;
    int getTokenPos() override;
    void next() override;
    void setLine(const QString &newLine, int lineNumber) override;
    bool isKeyword(const QString &word) override;
    TokenType getTokenType() override;
    void setState(const HighlighterState& rangeState) override;
    void resetState() override;
    HighlighterClass getClass() const override;
    QString getName() const override;

    QString languageName() override;
    HighlighterLanguage language() override;

    // SynHighlighter interface
public:
    HighlighterState getState() const override;

    // SynHighlighter interface
public:
    bool isIdentChar(const QChar &ch) const override;

    // SynHighlighter interface
public:
    QSet<QString> keywords() const override;
};

}
#endif // SYNEDITGLSLHIGHLIGHTER_H
