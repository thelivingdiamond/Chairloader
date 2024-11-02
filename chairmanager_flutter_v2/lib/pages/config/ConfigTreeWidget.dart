
import 'package:chairmanager_flutter_v2/models/Mod.dart';
import 'package:chairmanager_flutter_v2/models/ModConfig.dart';
import 'package:chairmanager_flutter_v2/pages/config/ConfigController.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:get/get.dart';

class ConfigTreeWidget extends StatelessWidget {
  const ConfigTreeWidget({super.key, required this.node, required this.mod});

  final IConfigNode node;
  final Mod mod;

  @override
  Widget build(BuildContext context) {
    ConfigController configController = Get.find();
    switch(node.type){
      case ConfigEntryType.bool:
        return SwitchListTile(
          controlAffinity: ListTileControlAffinity.leading,
          title: Row(
           mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Text(node.displayName ?? node.name),
              if(node.description != null)
                IconButton(
                  icon: const Icon(Icons.info),
                  onPressed: () {
                    showDialog(
                      context: context,
                      builder: (context) {
                        return AlertDialog(
                          title: Text(node.displayName ?? node.name),
                          content: Text(node.description ?? ""),
                        );
                      },
                    );
                  },
                ),

            ],
          ),
          value: node.value,
          onChanged: (value) {
            node.value = value;
            configController.markConfigAsDirty(mod);
          },
        );
      case ConfigEntryType.int:
        return ListTile(
            title: ConfigEditField(node: node, inputFormatters:  [ FilteringTextInputFormatter.allow(RegExp(r'^-?[0-9]*')), ],
              onChanged: (value) {
                if(int.tryParse(value) == null) {
                  return;
                }
                node.value = int.parse(value);
                configController.markConfigAsDirty(mod);
              },
            )
        );
      case ConfigEntryType.unsignedInt:
        return ListTile(
            title: ConfigEditField(node: node,
              inputFormatters:  [ FilteringTextInputFormatter.allow(RegExp(r'^[0-9]*')), ],
              onChanged: (value) {
                if(int.tryParse(value) == null) {
                  return;
                }
                node.value = int.parse(value);
                configController.markConfigAsDirty(mod);
              },
            )
        );
      case ConfigEntryType.int64:
        return ListTile(
          title: ConfigEditField(node: node,
            inputFormatters:  [ FilteringTextInputFormatter.allow(RegExp(r'^-?[0-9]*')), ],
            onChanged: (value) {
              if(int.tryParse(value) == null) {
                return;
              }
              node.value = int.parse(value);
              configController.markConfigAsDirty(mod);
            },
          )
        );
      case ConfigEntryType.unsignedInt64:
      // this one is bigint
        return ListTile(
          title: ConfigEditField(node: node,
            inputFormatters:  [ FilteringTextInputFormatter.allow(RegExp(r'^[0-9]*')), ],
            onChanged: (value) {
              if(BigInt.tryParse(value) == null) {
                return;
              }
              node.value = BigInt.parse(value);
              configController.markConfigAsDirty(mod);
            },
          )
        );
      case ConfigEntryType.float:
        return ListTile(
          title: ConfigEditField(node: node,
            inputFormatters:  [ FilteringTextInputFormatter.allow(RegExp(r'^-?[0-9]*\.?[0-9]*')), ],
            onChanged: (value) {
              if(double.tryParse(value) == null) {
                return;
              }
              node.value = double.parse(value);
              configController.markConfigAsDirty(mod);
            },
          )
        );
      case ConfigEntryType.string:
        return ListTile(
          title: ConfigEditField(node: node, inputFormatters: const [],
            onChanged: (value) {
              node.value = value;
              configController.markConfigAsDirty(mod);
            },
          )
        );
      case ConfigEntryType.enum_:
        var enumNode = node as ConfigLeafEnum;
        return ListTile(
            title: DropdownButtonFormField(
              decoration: InputDecoration(
                label: Text(node.displayName ?? node.name),
              ),
              items: enumNode.options.map((option) => DropdownMenuItem(
                value: option.value,
                child: Text(option.displayName ?? option.value),
              )).toList(),
              onChanged: (value) {
                enumNode.value = value;
                configController.markConfigAsDirty(mod);
              },
            )
        );
      case ConfigEntryType.xmlNode:
      // recursively build the tree with collapsible nodes
        return Container(
          decoration: BoxDecoration(
            border: Border(left: BorderSide(color: Theme.of(context).colorScheme.onSurface.withOpacity(0.1))),
          ),
          child: ExpansionTile(
            // backgroundColor: Theme.of(context).colorScheme.onSurface.withOpacity(0.025),
            childrenPadding: const EdgeInsets.only(left: 16),
            title: Row(
              mainAxisAlignment: MainAxisAlignment.spaceBetween,
              children: [
                Text(node.displayName ?? node.name, style: const TextStyle(fontWeight: FontWeight.bold)),
                if(node.description != null)
                  IconButton(
                    icon: const Icon(Icons.info),
                    onPressed: () {
                      showDialog(
                        context: context,
                        builder: (context) {
                          return AlertDialog(
                            title: Text(node.displayName ?? node.name),
                            content: Text(node.description ?? ""),
                          );
                        },
                      );
                    },
                  ),
              ],
            ),
            children: node.children.map((child) => ConfigTreeWidget(node: child, mod: mod,)).toList(),
          ),
        );
    }
    return Container();
  }
}

class ConfigEditField extends StatelessWidget {
  const ConfigEditField({super.key, required this.node, required this.inputFormatters, required this.onChanged});

  final IConfigNode node;
  final List<TextInputFormatter> inputFormatters;
  final Function(String value) onChanged;


  @override
  Widget build(BuildContext context) {
    return TextFormField(
      decoration: InputDecoration(
        label: Text(node.displayName ?? node.name),
        suffixIcon: node.description == null ? null : IconButton(
          icon: const Icon(Icons.info),
          onPressed: () {
            showDialog(
              context: context,
              builder: (context) {
                return AlertDialog(
                  title: Text(node.displayName ?? node.name),
                  content: Text(node.description ?? ""),
                );
              },
            );
          },
        ),
      ),
      keyboardType: TextInputType.number,
      initialValue: node.value.toString(),
      inputFormatters: inputFormatters,
      onChanged: onChanged,
    );
  }
}

