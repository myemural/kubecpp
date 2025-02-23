#include <exception>
#include <iostream>
#include <string>

#include <kubecpp/api/core_api.h>
#include <kubecpp/client/api_client.h>
#include <kubecpp/client/api_config.h>
#include <kubecpp/model/pod.h>

using namespace kubecpp::client;
using namespace kubecpp::api::core::v1;
using namespace kubecpp::model::core::v1;
using namespace kubecpp::model::internal::common;
using namespace kubecpp::model::internal::pod;

int main()
{
    try {
        const ApiConfig config{ R"(<PUT_YOUR_KUBECONFIG_PATH_HERE>)" };
        const ApiClient defaultClient = ApiClient(config);

        const Pod pod =
        PodBuilder()
        .ApiVersion("v1")
        .Kind("Pod")
        .Metadata(
        ObjectMetaBuilder().Name("test-pod").Namespace("default").Labels({ { "key1", "val2" }, { "key2", "val2" } }).Build())
        .Spec(PodSpecBuilder().Containers({ ContainerBuilder().Name("test-container").Image("busybox/latest").Build() }).Build())
        .Build();

        auto testJson = pod.ParseToJson();
        std::cout << testJson << '\n';

        const CoreApi instance{ defaultClient };
        auto res = instance.Create<Pod>("default", pod);
        if(res.HasData() && !res.IsFailed()) {
            std::cout << res.GetSuccessData().ParseToJson() << '\n';
        } else if(res.HasData() && res.IsFailed()) {
            std::cout << res.GetFailData().ParseToJson() << '\n';
        }
    } catch(const std::exception& except) {
        std::cout << "Error: " << except.what() << '\n';
    }

    return 0;
}