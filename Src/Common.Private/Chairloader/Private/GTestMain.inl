#include <Prey/CryCore/Platform/platform_impl.inl>

// TODO 2024-04-26: Remove this
struct ChairloaderGlobalEnvironment* gCL;

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
