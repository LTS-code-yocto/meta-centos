FILESEXTRAPATHS_prepend := "${THISDIR}/centos:"
CENTOS_SRC = "https://github.com/systemd/systemd/archive/v239.tar.gz" 

CENTOS_PATCHES = " \
	 file://0001-build-sys-Detect-whether-struct-statx-is-defined-in-.patch \
	 file://0002-logind-set-RemoveIPC-to-false-by-default.patch \
	 file://0003-pid1-bump-DefaultTasksMax-to-80-of-the-kernel-pid.ma.patch \
	 file://0004-Avoid-tmp-being-mounted-as-tmpfs-without-the-user-s-.patch \
	 file://0005-pid1-bump-maximum-number-of-process-in-user-slice-to.patch \
	 file://0006-rules-automatically-online-hot-plugged-CPUs.patch \
	 file://0007-rules-add-rule-for-naming-Dell-iDRAC-USB-Virtual-NIC.patch \
	 file://0008-rules-enable-memory-hotplug.patch \
	 file://0009-rules-reload-sysctl-settings-when-the-bridge-module-.patch \
	 file://0010-rules-load-sg-module.patch \
	 file://0011-rules-prandom-character-device-node-permissions.patch \
	 file://0012-rules-load-sg-driver-also-when-scsi_target-appears-4.patch \
	 file://0013-rules-don-t-hoplug-memory-on-s390x.patch \
	 file://0014-rules-disable-auto-online-of-hot-plugged-memory-on-I.patch \
	 file://0015-rules-introduce-old-style-by-path-symlinks-for-FCP-b.patch \
	 file://0016-Revert-udev-remove-WAIT_FOR-key.patch \
	 file://0017-net_setup_link-allow-renaming-interfaces-that-were-r.patch \
	 file://0018-units-drop-DynamicUser-yes-from-systemd-resolved.ser.patch \
	 file://0019-journal-remove-journal-audit-socket.patch \
	 file://0020-bus-move-BUS_DONT_DESTROY-calls-after-asserts.patch \
	 file://0021-random-seed-raise-POOL_SIZE_MIN-constant-to-1024.patch \
	 file://0022-cryptsetup-add-support-for-sector-size-option-9936.patch \
	 file://0023-cryptsetup-do-not-define-arg_sector_size-if-libgcryp.patch \
	 file://0024-units-don-t-enable-per-service-IP-firewall-by-defaul.patch \
	 file://0025-bus-message-do-not-crash-on-message-with-a-string-of.patch \
	 file://0026-Introduce-free_and_strndup-and-use-it-in-bus-message.patch \
	 file://0027-tests-backport-test_setup_logging.patch \
	 file://0028-journal-change-support-URL-shown-in-the-catalog-entr.patch \
	 file://0029-resolved-create-etc-resolv.conf-symlink-at-runtime.patch \
	 file://0030-dissect-image-use-right-comparison-function.patch \
	 file://0031-login-avoid-leak-of-name-returned-by-uid_to_name.patch \
	 file://0032-firewall-util-add-an-assert-that-we-re-not-overwriti.patch \
	 file://0033-journal-file-avoid-calling-ftruncate-with-invalid-fd.patch \
	 file://0034-dhcp6-make-sure-we-have-enough-space-for-the-DHCP6-o.patch \
	 file://0035-core-rename-queued_message-pending_reload_message.patch \
	 file://0036-core-when-we-can-t-send-the-pending-reload-message-s.patch \
	 file://0037-core-make-sure-we-don-t-throttle-change-signal-gener.patch \
	 file://0038-proc-cmdline-introduce-PROC_CMDLINE_RD_STRICT.patch \
	 file://0039-debug-generator-introduce-rd.-version-of-all-options.patch \
	 file://0040-chown-recursive-let-s-rework-the-recursive-logic-to-.patch \
	 file://0041-chown-recursive-also-drop-ACLs-when-recursively-chow.patch \
	 file://0042-chown-recursive-TAKE_FD-is-your-friend.patch \
	 file://0043-test-add-test-case-for-recursive-chown-ing.patch \
	 file://0044-Revert-sysctl.d-request-ECN-on-both-in-and-outgoing-.patch \
	 file://0045-detect-virt-do-not-try-to-read-all-of-proc-cpuinfo.patch \
	 file://0046-sd-bus-unify-three-code-paths-which-free-struct-bus_.patch \
	 file://0047-sd-bus-properly-initialize-containers.patch \
	 file://0048-cryptsetup-generator-introduce-basic-keydev-support.patch \
	 file://0049-cryptsetup-don-t-use-m-if-there-s-no-error-to-show.patch \
	 file://0050-cryptsetup-generator-don-t-return-error-if-target-di.patch \
	 file://0051-cryptsetup-generator-allow-whitespace-characters-in-.patch \
	 file://0052-rules-watch-metadata-changes-on-DASD-devices.patch \
	 file://0053-sysctl.d-switch-net.ipv4.conf.all.rp_filter-from-1-t.patch \
	 file://0054-tests-explicitly-enable-user-namespaces-for-TEST-13-.patch \
	 file://0055-nspawn-beef-up-netns-checking-a-bit-for-compat-with-.patch \
	 file://0056-test-Drop-SKIP_INITRD-for-QEMU-based-tests.patch \
	 file://0057-meson-rename-Ddebug-to-Ddebug-extra.patch \
	 file://0058-meson-check-whether-gnutls-supports-TCP-fast-open.patch \
	 file://0059-unit-don-t-add-Requires-for-tmp.mount.patch \
	 file://0060-tests-drop-the-precondition-check-for-inherited-flag.patch \
	 file://0061-core-when-deserializing-state-always-use-read_line-L.patch \
	 file://0062-core-enforce-a-limit-on-STATUS-texts-recvd-from-serv.patch \
	 file://0063-travis-enable-Travis-CI-on-CentOS-7.patch \
	 file://0064-travis-RHEL8-support.patch \
	 file://0065-travis-drop-the-SELinux-Fedora-workaround.patch \
	 file://0066-travis-fix-syntax-error-in-.travis.yml.patch \
	 file://0067-travis-reboot-the-container-before-running-tests.patch \
	 file://0068-coredump-remove-duplicate-MESSAGE-prefix-from-messag.patch \
	 file://0069-journald-remove-unnecessary.patch \
	 file://0070-journald-do-not-store-the-iovec-entry-for-process-co.patch \
	 file://0071-basic-process-util-limit-command-line-lengths-to-_SC.patch \
	 file://0072-coredump-fix-message-when-we-fail-to-save-a-journald.patch \
	 file://0073-procfs-util-expose-functionality-to-query-total-memo.patch \
	 file://0074-basic-prioq-add-prioq_peek_item.patch \
	 file://0075-journal-limit-the-number-of-entries-in-the-cache-bas.patch \
	 file://0076-journald-periodically-drop-cache-for-all-dead-PIDs.patch \
	 file://0077-process-util-don-t-use-overly-large-buffer-to-store-.patch \
	 file://0078-Revert-sysctl.d-switch-net.ipv4.conf.all.rp_filter-f.patch \
	 file://0079-journal-fix-syslog_parse_identifier.patch \
	 file://0080-journald-set-a-limit-on-the-number-of-fields-1k.patch \
	 file://0081-journald-when-processing-a-native-message-bail-more-.patch \
	 file://0082-journald-lower-the-maximum-entry-size-limit-to-for-n.patch \
	 file://0083-httpd-use-a-cleanup-function-to-call-MHD_destroy_res.patch \
	 file://0084-journal-remote-verify-entry-length-from-header.patch \
	 file://0085-journal-remote-set-a-limit-on-the-number-of-fields-i.patch \
	 file://0086-journald-correctly-attribute-log-messages-also-with-.patch \
	 file://0087-test-replace-echo-with-socat.patch \
	 file://0088-test-network-ignore-tunnel-devices-automatically-add.patch \
	 file://0089-rules-add-elevator-kernel-command-line-parameter.patch \
	 file://0090-rule-syntax-check-allow-PROGRAM-as-an-assignment.patch \
	 file://0091-rules-implement-new-memory-hotplug-policy.patch \
	 file://0092-LGTM-make-LGTM.com-use-meson-from-pip.patch \
	 file://0093-lgtm-use-python3.patch \
	 file://0094-tools-use-print-function-in-Python-3-code.patch \
	 file://0095-lgtm-add-a-custom-query-for-catching-the-use-of-fget.patch \
	 file://0096-lgtm-drop-redundant-newlines.patch \
	 file://0097-rules-add-the-rule-that-adds-elevator-kernel-command.patch \
	 file://0098-test-add-TEST-24-UNIT-TESTS-running-all-basic-tests-.patch \
	 file://0099-tests-create-the-asan-wrapper-automatically-if-syste.patch \
	 file://0100-tests-add-a-wrapper-for-when-systemd-is-built-with-A.patch \
	 file://0101-tests-redirect-ASAN-reports-on-journald-to-a-file.patch \
	 file://0102-tests-use-the-asan-wrapper-to-boot-a-VM-container-if.patch \
	 file://0103-tests-allow-passing-additional-arguments-to-nspawn-v.patch \
	 file://0104-tests-also-run-TEST-01-BASIC-in-an-unprivileged-cont.patch \
	 file://0105-test-don-t-overwrite-TESTDIR-if-already-set.patch \
	 file://0106-bus-socket-Fix-line_begins-to-accept-word-matching-f.patch \
	 file://0107-Refuse-dbus-message-paths-longer-than-BUS_PATH_SIZE_.patch \
	 file://0108-Allocate-temporary-strings-to-hold-dbus-paths-on-the.patch \
	 file://0109-sd-bus-if-we-receive-an-invalid-dbus-message-ignore-.patch \
	 file://0110-meson-drop-misplaced-Wl-undefined-argument.patch \
	 file://0111-Revert-core-one-step-back-again-for-nspawn-we-actual.patch \
	 file://0112-tree-wide-shorten-error-logging-a-bit.patch \
	 file://0113-nspawn-simplify-machine-terminate-bus-call.patch \
	 file://0114-nspawn-merge-two-variable-declaration-lines.patch \
	 file://0115-nspawn-rework-how-we-allocate-kill-scopes.patch \
	 file://0116-unit-enqueue-cgroup-empty-check-event-if-the-last-re.patch \
	 file://0117-Revert-journal-remove-journal-audit-socket.patch \
	 file://0118-journal-don-t-enable-systemd-journald-audit.socket-b.patch \
	 file://0119-logs-show-use-grey-color-for-de-emphasizing-journal-.patch \
	 file://0120-units-add-Install-section-to-tmp.mount.patch \
	 file://0121-nss-do-not-modify-errno-when-NSS_STATUS_NOTFOUND-or-.patch \
	 file://0122-util.h-add-new-UNPROTECT_ERRNO-macro.patch \
	 file://0123-nss-unportect-errno-before-writing-to-NSS-errnop.patch \
	 file://0124-seccomp-reduce-logging-about-failure-to-add-syscall-.patch \
	 file://0125-format-table-when-duplicating-a-cell-also-copy-the-c.patch \
	 file://0126-format-table-optionally-make-specific-cells-clickabl.patch \
	 file://0127-format-table-before-outputting-a-color-check-if-colo.patch \
	 file://0128-format-table-add-option-to-store-format-percent-and-.patch \
	 file://0129-format-table-optionally-allow-reversing-the-sort-ord.patch \
	 file://0130-format-table-add-table_update-to-update-existing-ent.patch \
	 file://0131-format-table-add-an-API-for-getting-the-cell-at-a-sp.patch \
	 file://0132-format-table-always-underline-header-line.patch \
	 file://0133-format-table-add-calls-to-query-the-data-in-a-specif.patch \
	 file://0134-format-table-make-sure-we-never-call-memcmp-with-NUL.patch \
	 file://0135-format-table-use-right-field-for-display.patch \
	 file://0136-format-table-add-option-to-uppercase-cells-on-displa.patch \
	 file://0137-format-table-never-try-to-reuse-cells-that-have-colo.patch \
	 file://0138-locale-util-add-logic-to-output-smiley-emojis-at-var.patch \
	 file://0139-analyze-add-new-security-verb.patch \
	 file://0140-tests-add-a-rudimentary-fuzzer-for-server_process_sy.patch \
	 file://0141-journald-make-it-clear-that-dev_kmsg_record-modifies.patch \
	 file://0142-journald-free-the-allocated-memory-before-returning-.patch \
	 file://0143-tests-rework-the-code-fuzzing-journald.patch \
	 file://0144-journald-make-server_process_native_message-compatib.patch \
	 file://0145-tests-add-a-fuzzer-for-server_process_native_message.patch \
	 file://0146-tests-add-a-fuzzer-for-sd-ndisc.patch \
	 file://0147-ndisc-fix-two-infinite-loops.patch \
	 file://0148-tests-add-reproducers-for-several-issues-uncovered-w.patch \
	 file://0149-tests-add-a-reproducer-for-an-infinite-loop-in-ndisc.patch \
	 file://0150-tests-add-a-reproducer-for-another-infinite-loop-in-.patch \
	 file://0151-fuzz-rename-fuzz-corpus-directory-to-just-fuzz.patch \
	 file://0152-test-add-testcase-for-issue-10007-by-oss-fuzz.patch \
	 file://0153-fuzz-unify-the-fuzz-regressions-directory-with-the-m.patch \
	 file://0154-test-bus-marshal-use-cescaping-instead-of-hexmem.patch \
	 file://0155-meson-add-Dlog-trace-to-set-LOG_TRACE.patch \
	 file://0156-meson-allow-building-resolved-and-machined-without-n.patch \
	 file://0157-meson-drop-duplicated-condition.patch \
	 file://0158-meson-use-.source_root-in-more-places.patch \
	 file://0159-meson-treat-all-fuzz-cases-as-unit-tests.patch \
	 file://0160-fuzz-bus-message-add-fuzzer-for-message-parsing.patch \
	 file://0161-bus-message-use-structured-initialization-to-avoid-u.patch \
	 file://0162-bus-message-avoid-an-infinite-loop-on-empty-structur.patch \
	 file://0163-bus-message-let-s-always-use-EBADMSG-when-the-messag.patch \
	 file://0164-bus-message-rename-function-for-clarity.patch \
	 file://0165-bus-message-use-define.patch \
	 file://0166-bus-do-not-print-null-if-the-message-has-unknown-typ.patch \
	 file://0167-bus-message-fix-calculation-of-offsets-table.patch \
	 file://0168-bus-message-remove-duplicate-assignment.patch \
	 file://0169-bus-message-fix-calculation-of-offsets-table-for-arr.patch \
	 file://0170-bus-message-drop-asserts-in-functions-which-are-wrap.patch \
	 file://0171-bus-message-output-debug-information-about-offset-tr.patch \
	 file://0172-bus-message-fix-skipping-of-array-fields-in-gvariant.patch \
	 file://0173-bus-message-also-properly-copy-struct-signature-when.patch \
	 file://0174-fuzz-bus-message-add-two-test-cases-that-pass-now.patch \
	 file://0175-bus-message-return-EBADMSG-not-EINVAL-on-invalid-gva.patch \
	 file://0176-bus-message-avoid-wrap-around-when-using-length-read.patch \
	 file://0177-util-do-not-use-stack-frame-for-parsing-arbitrary-in.patch \
	 file://0178-travis-enable-ASan-and-UBSan-on-RHEL8.patch \
	 file://0179-tests-keep-SYS_PTRACE-when-running-under-ASan.patch \
	 file://0180-tree-wide-various-ubsan-zero-size-memory-fixes.patch \
	 file://0181-util-introduce-memcmp_safe.patch \
	 file://0182-test-socket-util-avoid-memleak-reported-by-valgrind.patch \
	 file://0183-sd-journal-escape-binary-data-in-match_make_string.patch \
	 file://0184-capability-introduce-CAP_TO_MASK_CORRECTED-macro-rep.patch \
	 file://0185-sd-bus-use-size_t-when-dealing-with-memory-offsets.patch \
	 file://0186-sd-bus-call-cap_last_cap-only-once-in-has_cap.patch \
	 file://0187-mount-point-honour-AT_SYMLINK_FOLLOW-correctly.patch \
	 file://0188-travis-switch-from-trusty-to-xenial.patch \
	 file://0189-test-socket-util-Add-tests-for-receive_fd_iov-and-fr.patch \
	 file://0190-socket-util-Introduce-send_one_fd_iov-and-receive_on.patch \
	 file://0191-core-swap-order-of-n_storage_fds-and-n_socket_fds-pa.patch \
	 file://0192-execute-use-our-usual-syntax-for-defining-bit-masks.patch \
	 file://0193-core-introduce-new-Type-exec-service-type.patch \
	 file://0194-man-document-the-new-Type-exec-type.patch \
	 file://0195-sd-bus-allow-connecting-to-the-pseudo-container-.hos.patch \
	 file://0196-sd-login-let-s-also-make-sd-login-understand-.host.patch \
	 file://0197-test-add-test-for-Type-exec.patch \
	 file://0198-journal-gateway-explicitly-declare-local-variables.patch \
	 file://0199-tools-drop-unused-variable.patch \
	 file://0200-journal-gateway-use-localStorage-cursor-only-when-it.patch \
	 file://0201-sd-bus-deal-with-cookie-overruns.patch \
	 file://0202-journal-remote-do-not-request-Content-Length-if-Tran.patch \
	 file://0203-journal-do-not-remove-multiple-spaces-after-identifi.patch \
	 file://0204-cryptsetup-Do-not-fallback-to-PLAIN-mapping-if-LUKS-.patch \
	 file://0205-cryptsetup-call-crypt_load-for-LUKS-only-once.patch \
	 file://0206-cryptsetup-Add-LUKS2-token-support.patch \
	 file://0207-udev-scsi_id-fix-incorrect-page-length-when-get-devi.patch \
	 file://0208-Change-job-mode-of-manager-triggered-restarts-to-JOB.patch \
	 file://0209-bash-completion-analyze-support-security.patch \
	 file://0210-man-note-that-journal-does-not-validate-syslog-field.patch \
	 file://0211-rules-skip-memory-hotplug-on-ppc64.patch \
	 file://0212-mount-simplify-proc-self-mountinfo-handler.patch \
	 file://0213-mount-rescan-proc-self-mountinfo-before-processing-w.patch \
	 file://0214-swap-scan-proc-swaps-before-processing-waitid-result.patch \
	 file://0215-analyze-security-fix-potential-division-by-zero.patch \
	 file://0216-core-never-propagate-reload-failure-to-service-resul.patch \
	 file://0217-man-document-systemd-analyze-security.patch \
	 file://0218-man-reorder-and-add-examples-to-systemd-analyze-1.patch \
	 file://0219-travis-move-to-CentOS-8-docker-images.patch \
	 file://0220-travis-drop-SCL-remains.patch \
	 file://0221-syslog-fix-segfault-in-syslog_parse_priority.patch \
	 file://0222-sd-bus-make-strict-asan-shut-up.patch \
	 file://0223-travis-don-t-run-slow-tests-under-ASan-UBSan.patch \
	 file://0224-kernel-install-do-not-require-non-empty-kernel-cmdli.patch \
	 file://0225-ask-password-prevent-buffer-overrow-when-reading-fro.patch \
	 file://0226-core-try-to-reopen-dev-kmsg-again-right-after-mounti.patch \
	 file://0227-buildsys-don-t-garbage-collect-sections-while-linkin.patch \
	 file://0228-udev-introduce-CONST-key-name.patch \
	 file://0229-Call-getgroups-to-know-size-of-supplementary-groups-.patch \
	 file://0230-Consider-smb3-as-remote-filesystem.patch \
	 file://0231-process-util-introduce-pid_is_my_child-helper.patch \
	 file://0232-core-reduce-the-number-of-stalled-PIDs-from-the-watc.patch \
	 file://0233-core-only-watch-processes-when-it-s-really-necessary.patch \
	 file://0234-core-implement-per-unit-journal-rate-limiting.patch \
	 file://0235-path-stop-watching-path-specs-once-we-triggered-the-.patch \
	 file://0236-journald-fixed-assertion-failure-when-system-journal.patch \
	 file://0237-test-use-PBKDF2-instead-of-Argon2-in-cryptsetup.patch \
	 file://0238-test-mask-several-unnecessary-services.patch \
	 file://0239-test-bump-the-second-partition-s-size-to-50M.patch \
	 file://0240-shared-sleep-config-exclude-zram-devices-from-hibern.patch \
	 file://0241-selinux-don-t-log-SELINUX_INFO-and-SELINUX_WARNING-m.patch \
	 file://0242-sd-device-introduce-log_device_-macros.patch \
	 file://0243-udev-Add-id-program-and-rule-for-FIDO-security-token.patch \
	 file://0244-shared-but-util-drop-trusted-annotation-from-bus_ope.patch \
	 file://0245-sd-bus-adjust-indentation-of-comments.patch \
	 file://0246-resolved-do-not-run-loop-twice.patch \
	 file://0247-resolved-allow-access-to-Set-Link-and-Revert-methods.patch \
	 file://0248-resolved-query-polkit-only-after-parsing-the-data.patch \
	 file://0249-journal-rely-on-_cleanup_free_-to-free-a-temporary-s.patch \
	 file://0250-basic-user-util-allow-dots-in-user-names.patch \
	 file://0251-sd-bus-bump-message-queue-size-again.patch \
	 file://0252-tests-put-fuzz_journald_processing_function-in-a-.c-.patch \
	 file://0253-tests-add-a-fuzzer-for-dev_kmsg_record.patch \
	 file://0254-basic-remove-an-assertion-from-cunescape_one.patch \
	 file://0255-journal-fix-an-off-by-one-error-in-dev_kmsg_record.patch \
	 file://0256-tests-add-a-reproducer-for-a-memory-leak-fixed-in-30.patch \
	 file://0257-tests-add-a-reproducer-for-a-heap-buffer-overflow-fi.patch \
	 file://0258-test-initialize-syslog_fd-in-fuzz-journald-kmsg-too.patch \
	 file://0259-tests-add-a-fuzzer-for-process_audit_string.patch \
	 file://0260-journald-check-whether-sscanf-has-changed-the-value-.patch \
	 file://0261-tests-introduce-dummy_server_init-and-use-it-in-all-.patch \
	 file://0262-tests-add-a-fuzzer-for-journald-streams.patch \
	 file://0263-tests-add-a-fuzzer-for-server_process_native_file.patch \
	 file://0264-fuzz-journal-stream-avoid-assertion-failure-on-sampl.patch \
	 file://0265-journald-take-leading-spaces-into-account-in-syslog_.patch \
	 file://0266-Add-a-warning-about-the-difference-in-permissions-be.patch \
	 file://0267-execute-remove-one-redundant-comparison-check.patch \
	 file://0268-core-change-ownership-mode-of-the-execution-director.patch \
	 file://0269-core-dbus-execute-remove-unnecessary-initialization.patch \
	 file://0270-shared-cpu-set-util-move-the-part-to-print-cpu-set-i.patch \
	 file://0271-shared-cpu-set-util-remove-now-unused-CPU_SIZE_TO_NU.patch \
	 file://0272-Rework-cpu-affinity-parsing.patch \
	 file://0273-Move-cpus_in_affinity_mask-to-cpu-set-util.-ch.patch \
	 file://0274-test-cpu-set-util-add-simple-test-for-cpus_in_affini.patch \
	 file://0275-test-cpu-set-util-add-a-smoke-test-for-test_parse_cp.patch \
	 file://0276-pid1-parse-CPUAffinity-in-incremental-fashion.patch \
	 file://0277-pid1-don-t-reset-setting-from-proc-cmdline-upon-rest.patch \
	 file://0278-pid1-when-reloading-configuration-forget-old-setting.patch \
	 file://0279-test-execute-use-CPUSet-too.patch \
	 file://0280-shared-cpu-set-util-drop-now-unused-cleanup-function.patch \
	 file://0281-shared-cpu-set-util-make-transfer-of-cpu_set_t-over-.patch \
	 file://0282-test-cpu-set-util-add-test-for-dbus-conversions.patch \
	 file://0283-shared-cpu-set-util-introduce-cpu_set_to_range.patch \
	 file://0284-systemctl-present-CPUAffinity-mask-as-a-list-of-CPU-.patch \
	 file://0285-shared-cpu-set-util-only-force-range-printing-one-ti.patch \
	 file://0286-execute-dump-CPUAffinity-as-a-range-string-instead-o.patch \
	 file://0287-cpu-set-util-use-d-d-format-in-cpu_set_to_range_stri.patch \
	 file://0288-core-introduce-NUMAPolicy-and-NUMAMask-options.patch \
	 file://0289-core-disable-CPUAccounting-by-default.patch \
	 file://0290-set-kptr_restrict-1.patch \
	 file://0291-cryptsetup-reduce-the-chance-that-we-will-be-OOM-kil.patch \
	 file://0292-core-job-fix-breakage-of-ordering-dependencies-by-sy.patch \
	 file://0293-debug-generator-enable-custom-systemd.debug_shell-tt.patch \
	 file://0294-test-cpu-set-util-fix-comparison-for-allocation-size.patch \
	 file://0295-test-cpu-set-util-fix-allocation-size-check-on-i386.patch \
	 file://0296-catalog-fix-name-of-variable.patch \
	 file://0297-cryptsetup-add-keyfile-timeout-to-allow-a-keydev-tim.patch \
	 file://0298-cryptsetup-add-documentation-for-keyfile-timeout.patch \
	 file://0299-cryptsetup-use-unabbrieviated-variable-names.patch \
	 file://0300-cryptsetup-don-t-assert-on-variable-which-is-optiona.patch \
	 file://0301-cryptsetup-generator-guess-whether-the-keyfile-argum.patch \
	 file://0302-crypt-util-Translate-libcryptsetup-log-level-instead.patch \
	 file://0303-cryptsetup-add-some-commenting-about-EAGAIN-generati.patch \
	 file://0304-cryptsetup-downgrade-a-log-message-we-ignore.patch \
	 file://0305-cryptsetup-rework-how-we-log-about-activation-failur.patch \
	 file://0306-rules-reintroduce-60-alias-kmsg.rules.patch \
	 file://0307-sd-bus-make-rqueue-wqueue-sizes-of-type-size_t.patch \
	 file://0308-sd-bus-reorder-bus-ref-and-bus-message-ref-handling.patch \
	 file://0309-sd-bus-make-sure-dispatch_rqueue-initializes-return-.patch \
	 file://0310-sd-bus-drop-two-inappropriate-empty-lines.patch \
	 file://0311-sd-bus-initialize-mutex-after-we-allocated-the-wqueu.patch \
	 file://0312-sd-bus-always-go-through-sd_bus_unref-to-free-messag.patch \
	 file://0313-bus-message-introduce-two-kinds-of-references-to-bus.patch \
	 file://0314-sd-bus-introduce-API-for-re-enqueuing-incoming-messa.patch \
	 file://0315-sd-event-add-sd_event_source_disable_unref-helper.patch \
	 file://0316-polkit-when-authorizing-via-PK-let-s-re-resolve-call.patch \
	 file://0317-sysctl-let-s-by-default-increase-the-numeric-PID-ran.patch \
	 file://0318-journal-do-not-trigger-assertion-when-journal_file_c.patch \
	 file://0319-journal-use-cleanup-attribute-at-one-more-place.patch \
	 file://0320-sd-bus-use-queue-message-references-for-managing-r-w.patch \
	 file://0321-pid1-make-sure-to-restore-correct-default-values-for.patch \
	 file://0322-main-introduce-a-define-HIGH_RLIMIT_MEMLOCK-similar-.patch \
	 file://0323-seccomp-introduce-seccomp_restrict_suid_sgid-for-blo.patch \
	 file://0324-test-add-test-case-for-restrict_suid_sgid.patch \
	 file://0325-core-expose-SUID-SGID-restriction-as-new-unit-settin.patch \
	 file://0326-analyze-check-for-RestrictSUIDSGID-in-systemd-analyz.patch \
	 file://0327-man-document-the-new-RestrictSUIDSGID-setting.patch \
	 file://0328-units-turn-on-RestrictSUIDSGID-in-most-of-our-long-r.patch \
	 file://0329-core-imply-NNP-and-SUID-SGID-restriction-for-Dynamic.patch \
	 file://0330-cgroup-introduce-support-for-cgroup-v2-CPUSET-contro.patch \
	 file://0331-pid1-fix-DefaultTasksMax-initialization.patch \
	 file://0332-cgroup-make-sure-that-cpuset-is-supported-on-cgroup-.patch \
	 file://0333-test-introduce-TEST-36-NUMAPOLICY.patch \
	 file://0334-test-replace-tail-f-with-journal-cursor-which-should.patch \
	 file://0335-test-support-MPOL_LOCAL-matching-in-unpatched-strace.patch \
	 file://0336-test-make-sure-the-strace-process-is-indeed-dead.patch \
	 file://0337-test-skip-the-test-on-systems-without-NUMA-support.patch \
	 file://0338-test-give-strace-some-time-to-initialize.patch \
	 file://0339-test-add-a-simple-sanity-check-for-systems-without-N.patch \
	 file://0340-test-drop-the-missed-exit-1-expression.patch \
	 file://0341-test-replace-cursor-file-with-a-plain-cursor.patch \
	 file://0342-cryptsetup-Treat-key-file-errors-as-a-failed-passwor.patch \
	 file://0343-pid1-fix-the-names-of-AllowedCPUs-and-AllowedMemoryN.patch \
	 file://0344-core-fix-re-realization-of-cgroup-siblings.patch \
	 file://0345-basic-use-comma-as-separator-in-cpuset-cgroup-cpu-ra.patch \
	 file://0346-swap-finish-the-secondary-swap-units-jobs-if-deactiv.patch \
	 file://0347-pid1-add-new-kernel-cmdline-arg-systemd.cpu_affinity.patch \
	 file://0348-sd-journal-close-journal-files-that-were-deleted-by-.patch \
	 file://0349-sd-journal-remove-the-dead-code-and-actually-fix-146.patch \
	 file://0350-test-do-not-use-global-variable-to-pass-error.patch \
	 file://0351-test-install-libraries-required-by-tests.patch \
	 file://0352-test-introduce-install_zoneinfo.patch \
	 file://0353-test-replace-duplicated-Makefile-by-symbolic-link.patch \
	 file://0354-test-add-paths-of-keymaps-in-install_keymaps.patch \
	 file://0355-test-make-install_keymaps-optionally-install-more-ke.patch \
	 file://0356-test-fs-util-skip-some-tests-when-running-in-unprivi.patch \
	 file://0357-test-process-util-skip-several-verifications-when-ru.patch \
	 file://0358-test-execute-also-check-python3-is-installed-or-not.patch \
	 file://0359-test-execute-skip-several-tests-when-running-in-cont.patch \
	 file://0360-test-introduce-test_is_running_from_builddir.patch \
	 file://0361-test-make-test-catalog-relocatable.patch \
	 file://0362-test-parallelize-tasks-in-TEST-24-UNIT-TESTS.patch \
	 file://0363-test-try-to-determine-QEMU_SMP-dynamically.patch \
	 file://0364-test-store-coredumps-in-journal.patch \
	 file://0365-udev-rules-make-tape-changers-also-apprear-in-dev-ta.patch \
	 file://0366-nspawn-move-payload-to-sub-cgroup-first-then-sync-cg.patch \
	 file://0367-nspawn-chown-the-legacy-hierarchy-when-it-s-used-in-.patch \
	"
