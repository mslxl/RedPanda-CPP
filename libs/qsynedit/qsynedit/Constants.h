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
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <QSet>
#include <QChar>

namespace  QSynedit {

extern const QSet<QChar> WordBreakChars;
extern const QChar SpaceGlyph;
extern const QChar TabGlyph;
extern const QChar LineBreakGlyph;
extern const QChar SoftBreakGlyph;


#define MAX_SCROLL 65535

#define SYN_ATTR_COMMENT    0
#define SYN_ATTR_IDENTIFIER 1
#define SYN_ATTR_KEYWORD    2
#define SYN_ATTR_STRING     3
#define SYN_ATTR_WHITESPACE 4
#define SYN_ATTR_SYMBOL     5

// names for highlighter attributes
#define SYNS_AttrAreaAIdentifier    "Area A Identifier"
#define SYNS_AttrArrowHead          "ArrowHead"
#define SYNS_AttrAsm                "Asm"
#define SYNS_AttrAsmComment         "Asm Comment"
#define SYNS_AttrAsmKey             "Asm Key"
#define SYNS_AttrAssembler          "Assembler"
#define SYNS_AttrAttribute          "Attribute"
#define SYNS_AttrAttributeName      "Attribute Name"
#define SYNS_AttrAttributeValue     "Attribute Value"
#define SYNS_AttrBasicTypes         "Basic Types"
#define SYNS_AttrBlock              "Block"
#define SYNS_AttrBoolean            "Boolean value"
#define SYNS_AttrBrackets           "Brackets"
#define SYNS_AttrCDATASection       "CDATA Section"
#define SYNS_AttrCharacter          "Character"
#define SYNS_AttrClass              "Class"
#define SYNS_AttrColor              "Color Value"
#define SYNS_AttrComment            "Comment"
#define SYNS_AttrCondition          "Condition"
#define SYNS_AttrConditionalComment "Conditional Comment"
#define SYNS_AttrDataType           "Data Type"
#define SYNS_AttrDebugLines         "Debugging Lines"
#define SYNS_AttrDefaultPackage     "Default Packages"
#define SYNS_AttrDelimitedIdentifier    "Delimited Identifier"
#define SYNS_AttrDir                    "Direction"
#define SYNS_AttrDirections             "Directions"
#define SYNS_AttrDirective              "Directive"
#define SYNS_AttrDOCTYPESection         "DOCTYPE Section"
#define SYNS_AttrDocumentation          "Documentation"
#define SYNS_AttrElementName            "Element Name"
#define SYNS_AttrEmbedSQL               "Embedded SQL"
#define SYNS_AttrEmbedText              "Embedded Text"
#define SYNS_AttrEntityReference        "Entity Reference"
#define SYNS_AttrEscapeAmpersand        "Escape Ampersand"
#define SYNS_AttrEvent                  "Event"
#define SYNS_AttrException              "Exception"
#define SYNS_AttrFirstTri               "FirstTri"
#define SYNS_AttrFloat                  "Float"
#define SYNS_AttrForm                   "Form"
#define SYNS_AttrFourthTri              "FourthTri"
#define SYNS_AttrFunction               "Function"
#define SYNS_AttrFunctionParameter      "Function Parameter"
#define SYNS_AttrGlobalVariable         "Global variable"
#define SYNS_AttrHexadecimal            "Hexadecimal"
#define SYNS_AttrIcon                   "Icon Reference"
#define SYNS_AttrIdentifier             "Identifier"
#define SYNS_AttrIllegalChar            "Illegal Char"
#define SYNS_AttrInclude                "Include"
#define SYNS_AttrIndicator "Indicator Area"
#define SYNS_AttrIndirect "Indirect"
#define SYNS_AttrInvalidSymbol "Invalid Symbol"
#define SYNS_AttrInternalFunction "Internal Function"
#define SYNS_AttrKey "Key"
#define SYNS_AttrLabel "Label"
#define SYNS_AttrLace "Lace"
#define SYNS_AttrLocalVariable "Local Variable"
#define SYNS_AttrLine "Line"
#define SYNS_AttrMacro "Macro"
#define SYNS_AttrMarker "Marker"
#define SYNS_AttrMathMode "Math Mode"
#define SYNS_AttrMessage "Message"
#define SYNS_AttrMiscellaneous "Miscellaneous"
#define SYNS_AttrNamespaceAttrName "Namespace Attribute Name"
#define SYNS_AttrNamespaceAttrValue "Namespace Attribute Value"
#define SYNS_AttrNonReservedKeyword   "Non-reserved Keyword"
#define SYNS_AttrNull "Null"
#define SYNS_AttrNumber "Number"
#define SYNS_AttrOctal "Octal"
#define SYNS_AttrOperator "Operator"
#define SYNS_AttrOperatorAndSymbols "Operator And Symbols"
#define SYNS_AttrOpLine "OpLine"
#define SYNS_AttrPLSQL                "PL/SQL Reserved Word"
#define SYNS_AttrPragma "Pragma"
#define SYNS_AttrPredefined "Predefined"
#define SYNS_AttrPreprocessor "Preprocessor"
#define SYNS_AttrProcessingInstr "Processing Instruction"
#define SYNS_AttrQuad "Quad"
#define SYNS_AttrQualifier "Qualifier"
#define SYNS_AttrRegister "Register"
#define SYNS_AttrReservedWord "Reserved Word"
#define SYNS_AttrResultValue "Result Value"
#define SYNS_AttrRoundBracket "Round Bracket"
#define SYNS_AttrRpl "Rpl"
#define SYNS_AttrRplKey "Rpl Key"
#define SYNS_AttrRplComment "Rpl Comment"
#define SYNS_AttrSASM "SASM"
#define SYNS_AttrSASMComment "SASM Comment"
#define SYNS_AttrSASMKey "SASM Key"
#define SYNS_AttrSecondReservedWord "Second Reserved Word"
#define SYNS_AttrSecondTri "SecondTri"
#define SYNS_AttrSection "Section"
#define SYNS_AttrSequence "Sequence Number Area"
#define SYNS_AttrShape "Shape"
#define SYNS_AttrSingleString "Single Quoted String"
#define SYNS_AttrSpace "Space"
#define SYNS_AttrSpecialVariable "Special Variable"
#define SYNS_AttrSQLKey "SQL Keyword"
#define SYNS_AttrSQLPlus "SQL*Plus Command"
#define SYNS_AttrSquareBracket "Square Bracket"
#define SYNS_AttrString "String"
#define SYNS_AttrStringEscapeSequences "Escape sequences"
#define SYNS_AttrSymbol "Symbol"
#define SYNS_AttrSyntaxError "Syntax Error"
#define SYNS_AttrSystem "System Functions and Variables"
#define SYNS_AttrSystemValue "System Value"
#define SYNS_AttrTagArea "Tag Area"
#define SYNS_AttrTableName "Table Name"
#define SYNS_AttrTerminator "Terminator"
#define SYNS_AttrTeXCommand "TeX Command"
#define SYNS_AttrText "Text"
#define SYNS_AttrTextMathMode "Text in Math Mode"
#define SYNS_AttrThirdTri "ThirdTri"
#define SYNS_AttrTriangle "Triangle"
#define SYNS_AttrUnknownWord "Unknown Word"
#define SYNS_AttrURI "URI"
#define SYNS_AttrUser "User Functions and Variables"
#define SYNS_AttrUserFunction "User Functions"
#define SYNS_AttrValue "Value"
#define SYNS_AttrVariable "Variable"
#define SYNS_AttrVisitedURI "Visited URI"
#define SYNS_AttrVrmlAppearance "Vrml_Appearance"
#define SYNS_AttrVrmlAttribute "Vrml_Attribute"
#define SYNS_AttrVrmlDefinition "Vrml_Definition"
#define SYNS_AttrVrmlEvent "Vrml_Event"
#define SYNS_AttrVrmlGrouping "Vrml_Grouping"
#define SYNS_AttrVrmlInterpolator "Vrml_Interpolator"
#define SYNS_AttrVrmlLight "Vrml_Light"
#define SYNS_AttrVrmlNode "Vrml_Node"
#define SYNS_AttrVrmlParameter "Vrml_Parameter"
#define SYNS_AttrVrmlProto "Vrml_Proto"
#define SYNS_AttrVrmlSensor "Vrml_Sensor"
#define SYNS_AttrVrmlShape "Vrml_Shape"
#define SYNS_AttrVrmlShape_Hint "Vrml_Shape_Hint"
#define SYNS_AttrVrmlTime_dependent "Vrml_Time_dependent"
#define SYNS_AttrVrmlViewpoint "Vrml_Viewpoint"
#define SYNS_AttrVrmlWorldInfo "Vrml_WorldInfo"
#define SYNS_AttrWhitespace "Whitespace"
#define SYNS_AttrX3DDocType "X3DDocType"
#define SYNS_AttrX3DHeader "X3DHeader"
// names of exporter output formats
#define SYNS_ExporterFormatHTML "HTML"
#define SYNS_ExporterFormatRTF "RTF"
#define SYNS_ExporterFormatTeX "TeX"

#define SYN_HIGHLIGHTER_CPP "SynCppHighlighter"
#define SYN_HIGHLIGHTER_ASM "SynASMHighlighter"
#define SYN_HIGHLIGHTER_GLSL "SynGLSLHighlighter"

}

#endif // CONSTANTS_H
