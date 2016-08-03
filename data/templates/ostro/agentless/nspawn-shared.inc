Type=simple
TimeoutStopSec=5
{SET-GROUPS}({SERVICE})
{SET-ENVIRONMENT}({CONTAINER}, {SERVICE})
{PREPARE-CONTAINER}()
ExecStart=/usr/bin/systemd-nspawn \
    --keep-unit \
    --share-system \
    -M {MACHINE} \
    -D {CR} \
    --user {USER} \
    {BIND-RO}({AR}, '/self') \
    {BIND-RW}({HOME}({USER}), {CONCAT}('/home/', {USER})) \
    {OVERLAY-RW}('/etc') \
    {OVERLAY-RW}('/var') \
    {OVERLAY-RO}('/lib') \
    {OVERLAY-RO}('/sbin') \
    {OVERLAY-RO}('/bin') \
    {BIND-RO}('/usr', '/usr') \
    {TMPFS}('/tmp', '0755') \
    {NETWORK}({CONTAINER}) \
    {COMMAND}({CONTAINER}, {SERVICE})