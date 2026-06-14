# ReconX

A native-**Windows** network reconnaissance and vulnerability scanner, written from scratch in **C** (Winsock).

Point it at a host or a subnet (`192.168.1.0/24`) and it walks the full recon pipeline — discover live hosts, scan their ports, identify the services, flag known vulnerabilities, and report. A from-the-socket-up take on what tools like `nmap` and Nikto do.

>  **For authorized testing only.** Scan machines you own or have written permission to test.

## What this tool does

```
                 ┌─────────────┐
   192.168.1.0/24│  DISCOVERY  │  Which hosts are alive?      (ICMP ping)
        ───────► │             │ ───────────────────────────►  .10 .15 .22
                 └─────────────┘
                       │
                       ▼
                 ┌─────────────┐
                 │ PORT SCAN   │  Which ports are open?       (TCP connect)
                 │             │ ───────────────────────────►  22, 80, 443
                 └─────────────┘
                       │
                       ▼
                 ┌─────────────┐
                 │  SERVICE ID │  What's running there?       (banner grabbing)
                 │             │ ───────────────────────────►  OpenSSH 8.9, Apache 2.4.49
                 └─────────────┘
                       │
                       ▼
                 ┌─────────────┐
                 │   VULN      │  Is it vulnerable?           (CVE lookup, weak config)
                 │   CHECK     │ ───────────────────────────►  CVE-2021-41773 [CRITICAL]
                 └─────────────┘
                       │
                       ▼
                 ┌─────────────┐
                 │  REPORT     │  Color CLI + JSON/HTML out
                 └─────────────┘
```