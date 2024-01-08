import 'package:fluent_ui/fluent_ui.dart';
import 'package:get/get.dart';

class DialogPageViewController extends GetxController {
  DialogPageViewController({required this.pageCount});
  var pageController = PageController(initialPage: 0).obs;
  var pageIndex = 0.obs;
  final int pageCount;

  @override
  void onInit() {
    super.onInit();
    pageController.value.addListener(() {
      pageIndex.value = pageController.value.page!.round();
    });
  }

  void nextPage(){
    pageController.value.nextPage(duration: Duration(milliseconds: 300), curve: Curves.easeInOut);
  }

  void previousPage(){
    pageController.value.previousPage(duration: Duration(milliseconds: 300), curve: Curves.easeInOut);
  }

  void goToPage(int page){
    pageController.value.animateToPage(page, duration: Duration(milliseconds: 300), curve: Curves.easeInOut);
  }

  void back(){
    Get.back();
  }
}