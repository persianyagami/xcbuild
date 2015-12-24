/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree. An additional grant
 of patent rights can be found in the PATENTS file in the same directory.
 */

#ifndef __pbxbuild_NinjaExecutor_h
#define __pbxbuild_NinjaExecutor_h

#include <pbxbuild/Build/Executor.h>
#include <builtin/builtin.h>

namespace pbxbuild {
namespace Build {

class NinjaExecutor : public Executor {
public:
    NinjaExecutor(std::shared_ptr<Formatter> const &formatter, bool dryRun);
    ~NinjaExecutor();

public:
    virtual bool build(
        BuildEnvironment const &buildEnvironment,
        BuildContext const &buildContext,
        BuildGraph<pbxproj::PBX::Target::shared_ptr> const &targetGraph);

public:
    virtual std::pair<bool, std::vector<ToolInvocation const>> buildTarget(
        pbxproj::PBX::Target::shared_ptr const &target,
        TargetEnvironment const &targetEnvironment,
        std::vector<ToolInvocation const> const &invocations);

public:
    static std::unique_ptr<NinjaExecutor>
    Create(std::shared_ptr<Formatter> const &formatter, bool dryRun);
};

}
}

#endif // !__pbxbuild_NinjaExecutor_h
