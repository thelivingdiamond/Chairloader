

import 'package:chairmanager_flutter_v2/models/GenericLogMessage.dart';
import 'package:flutter/material.dart';

class GenericLogView extends StatelessWidget {
  const GenericLogView({super.key, required this.messages, this.itemPadding});

  final List<GenericLogMessage> messages;
  final EdgeInsetsGeometry? itemPadding;

  @override
  Widget build(BuildContext context) {
    return ListView.builder(
      itemCount: messages.length,
      reverse: true,
      itemBuilder: (context, index) {
        return Container(
            padding: itemPadding,
            color: index.isEven ? Colors.grey[600]?.withOpacity(0.1) : null,
            child: Text(messages[messages.length - 1 - index].message, style: TextStyle(color: messages[messages.length - 1 - index].logColor),
            )
        );
      },
    );
  }
}
