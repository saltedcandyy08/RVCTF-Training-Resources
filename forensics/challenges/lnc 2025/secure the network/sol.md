LNC25{Dn5_eXF1ltR4T1on_g0_bRRrr}

```
strings = re.findall(rb'[\x20-\x7E]{4,}', pcap_bytes)
candidates = [s[1:] for s in strings if s.startswith(b'<') and len(s) > 30]
```

```
root:$y$j9T$…$UifTFESyfx
daemon:*
…
kali:LNC25{Dn5_eXF1ltR4T1on_g0_bRRrr}:20078:0:99999:7:::
```

It’s the server’s /etc/shadow being exfiltrated.

