//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef _ELASTOS_DROID_CALCULATOR3_EXPRESSION_CCALCULATOREXPRESSIONTOKENIZER_H__
#define _ELASTOS_DROID_CALCULATOR3_EXPRESSION_CCALCULATOREXPRESSIONTOKENIZER_H__

#include "_Elastos_Droid_Calculator3_Expression_CCalculatorExpressionTokenizer.h"
#include "elastos/droid/calculator3/expression/CalculatorExpressionTokenizer.h"

namespace Elastos {
namespace Droid {
namespace Calculator3 {
namespace Expression {

CarClass(CCalculatorExpressionTokenizer), public CalculatorExpressionTokenizer
{
public:
    CAR_OBJECT_DECL()
};

} // namespace Expression
} // namespace Calculator3
} // namespace Droid
} // namespace Elastos

#endif // _ELASTOS_DROID_CALCULATOR3_EXPRESSION_CCALCULATOREXPRESSIONTOKENIZER_H__