cmd_/home/skurichi/mywork/kmod/modules.order := {   echo /home/skurichi/mywork/kmod/node.ko; :; } | awk '!x[$$0]++' - > /home/skurichi/mywork/kmod/modules.order
